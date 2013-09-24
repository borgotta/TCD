#include "fornster_detector.h"
#include "util.h"

using namespace std;
using namespace cv;

FornsterDetector::FornsterDetector() {};

void FornsterDetector::init(Mat image, float sigma) { 
	done = false;
	image.convertTo(m_image, CV_32F);

	m_sigmaI = sigma;
	m_height = m_image.rows;
	m_width = m_image.cols;
	setDerivatives();
	setResponse();
	done = true;
}

void FornsterDetector::setDerivatives() {
	preprocess();
	preprocess2();
}

void FornsterDetector::preprocess() {
	GaussianBlur(m_image, m_image, Size(0,0), m_sigmaI);
	m_image.copyTo(m_dIdx);
	m_image.copyTo(m_dIdy);

	vector<float> dfilter, ifilter;
	dfilter.resize(3);
	dfilter[0] = -1.0;  dfilter[1] = 0;  dfilter[2] = 1.0;
	ifilter.resize(3);
	ifilter[0] = 1.0 / 3.0;  ifilter[1] = 1.0 / 3.0;  ifilter[2] = 1.0 / 3.0;

	convolveX(m_dIdx, dfilter, m_dIdx);
	convolveY(m_dIdy, dfilter, m_dIdy);
}

void FornsterDetector::preprocess2() {
	m_dIdxdIdx = Mat::zeros(m_height, m_width, CV_32F);  
	m_dIdydIdy = Mat::zeros(m_height, m_width, CV_32F);
	m_dIdxdIdy = Mat::zeros(m_height, m_width, CV_32F);

	float *pm_dIdxdIdx = m_dIdxdIdx.ptr<float>();
	float *pm_dIdydIdy = m_dIdydIdy.ptr<float>();
	float *pm_dIdxdIdy = m_dIdxdIdy.ptr<float>();
	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			
			pm_dIdxdIdx[y*m_width + x] += m_dIdx.at<float>(y,x) * m_dIdx.at<float>(y,x);
			pm_dIdydIdy[y*m_width + x] += m_dIdy.at<float>(y,x) * m_dIdy.at<float>(y,x);
			pm_dIdxdIdy[y*m_width + x] += m_dIdx.at<float>(y,x) * m_dIdy.at<float>(y,x);
		}
	}

	//----------------------------------------------------------------------
	// blur
	GaussianBlur(m_dIdxdIdx, m_dIdxdIdx, Size(0,0), m_sigmaI*m_sigmaI);
	GaussianBlur(m_dIdydIdy, m_dIdydIdy, Size(0,0), m_sigmaI*m_sigmaI);
	GaussianBlur(m_dIdxdIdy, m_dIdxdIdy, Size(0,0), m_sigmaI*m_sigmaI);
}

void FornsterDetector::setResponse() {
	m_qResponse = Mat::zeros(m_height, m_width, CV_32F);
	m_wResponse = Mat::zeros(m_height, m_width, CV_32F);

	m_w = 0;
	float total = m_height*m_width;

	float *pm_qResponse = m_qResponse.ptr<float>();
	float *pm_wResponse = m_wResponse.ptr<float>();

	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {

			const float D = m_dIdxdIdx.at<float>(y,x) * m_dIdydIdy.at<float>(y,x) - m_dIdxdIdy.at<float>(y,x) * m_dIdxdIdy.at<float>(y,x);
			const float tr = m_dIdxdIdx.at<float>(y,x) + m_dIdydIdy.at<float>(y,x);
			const float w = tr == 0 ? 0.0 : D / tr;
			pm_wResponse[y*m_width + x] = w > 0.0 ? w : 0.0;
			m_w += w / total;
			const float q = tr == 0.0 ? 0.0 : (4 * w / tr);
			//if (q != 0.0) cout<<"q="<<q<<" ";
			pm_qResponse[y*m_width + x] = q >= 0.0 && q <= 1.0 ? q : 0.0; // (4*D)/tr^2
		}
	}
}

vector<Point2i> FornsterDetector::getCorners(float w, float q, int wind_n) {
	vector<Point2i> dst = vector<Point2i>();
	const float w_thresh = w * m_w; 
	Mat tempW, tempQ;
	tempW = m_wResponse * (1.0/m_w);
	tempQ = m_wResponse + m_qResponse;
	//nonMaximaSuppresionFloat(m_wResponse, wind_n, tempW);
	nonMaximaSuppresionFloat(tempQ, wind_n, tempW);
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (tempW.at<float>(y,x) >= (w+q) && m_wResponse.at<float>(y,x) >= w_thresh && m_qResponse.at<float>(y,x) >= q) {
				dst.push_back(Point2i(x,y));
			}
		}
	}
	cout<<"Corners detected: "<<dst.size()<<endl;
	return dst;
};

Mat FornsterDetector::getResponseW() {
	return m_wResponse;
};

Mat FornsterDetector::getResponseQ() {
	return m_qResponse;
}