#include "harris_detector.h"
#include "util.h"
#include <limits>

using namespace std;
using namespace cv;


HarrisDetector::HarrisDetector() {}
HarrisDetector::~HarrisDetector() {}
void HarrisDetector::init(Mat image, float sigma, float k) {
	//GaussianBlur(image, m_image, Size(3,3), 0);
	done = false;
	image.convertTo(m_image, CV_32F);

	m_k = k;
	m_height = m_image.rows;
	m_width = m_image.cols;
	m_sigmaD = sigma;
	m_sigmaI = sigma;
	setGaussD(m_sigmaD, m_gaussD);
	setGaussI(m_sigmaI, m_gaussI); 
	setDerivatives();
	setResponse();
	done = true;
}

void HarrisDetector::setDerivatives() {
	preprocess();
	preprocess2();
}

void HarrisDetector::preprocess() {
	//GaussianBlur(m_image, m_dIdx, Size(5,5), 0);
	m_image.copyTo(m_dIdx);
	m_image.copyTo(m_dIdy);
	//m_dIdx = m_image.clone();
	//m_dIdx = m_image;

	vector<float> dfilter, ifilter;
	dfilter.resize(3);
	dfilter[0] = -1.0;  dfilter[1] = 0;  dfilter[2] = 1.0;
	ifilter.resize(3);
	ifilter[0] = 1.0 / 3.0;  ifilter[1] = 1.0 / 3.0;  ifilter[2] = 1.0 / 3.0;

	convolveX(m_dIdx, dfilter, m_dIdx);
	//convolveY(m_dIdx, ifilter, m_dIdx);
	//convolveX(m_dIdx, m_gaussD, m_dIdx);

	//m_dIdy = m_image.clone();
	//GaussianBlur(m_image, m_dIdy, Size(5,5), 1);
	
	//m_dIdy = m_image;

	//convolveX(m_dIdy, ifilter, m_dIdy);
	convolveY(m_dIdy, dfilter, m_dIdy);
	//convolveY(m_dIdy, m_gaussD, m_dIdy);
}

void HarrisDetector::preprocess2() {
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

  //{
  //  vector<vector<Vec3f> >().swap(m_dIdx);
  //  vector<vector<Vec3f> >().swap(m_dIdy);
  //}
  
  //----------------------------------------------------------------------
  // blur
  
  //----------------------------------------------------------------------
  // m_dIdxdIdx
	GaussianBlur(m_dIdxdIdx, m_dIdxdIdx, Size(3,3), 0);
  //convolveX(m_dIdxdIdx, m_gaussI, m_dIdxdIdx);
  //convolveY(m_dIdxdIdx, m_gaussI, m_dIdxdIdx);
  
  //----------------------------------------------------------------------
  // m_dIdydIdy
	GaussianBlur(m_dIdydIdy, m_dIdydIdy, Size(3,3), 0);
  //convolveX(m_dIdydIdy, m_gaussI, m_dIdydIdy);
  //convolveY(m_dIdydIdy, m_gaussI, m_dIdydIdy);
  
  //----------------------------------------------------------------------
  // m_dIdxdIdy
	GaussianBlur(m_dIdxdIdy, m_dIdxdIdy, Size(3,3), 0);
  //convolveX(m_dIdxdIdy, m_gaussI, m_dIdxdIdy);
  //convolveY(m_dIdxdIdy, m_gaussI, m_dIdxdIdy);
}

void HarrisDetector::setResponse() {
	m_response = Mat::zeros(m_height, m_width, CV_32F);
	float *pm_response = m_response.ptr<float>();
	float min = numeric_limits<float>::max();
	float max = numeric_limits<float>::lowest();
	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			//const float dIdxdIdx = m_dIdxdIdx.at<float>(y,x);
			//const float dIdydIdy = m_dIdydIdy.at<float>(y,x);
			//const float dIdxdIdy = m_dIdxdIdy.at<float>(y,x);
			//if (dIdydIdy != 0.0) cout<<"dIdydIdy("<<y<<","<<x<<") = "<<dIdydIdy<<endl;
			const float D = m_dIdxdIdx.at<float>(y,x) * m_dIdydIdy.at<float>(y,x) - m_dIdxdIdy.at<float>(y,x) * m_dIdxdIdy.at<float>(y,x);
			const float tr = m_dIdxdIdx.at<float>(y,x) + m_dIdydIdy.at<float>(y,x);
			const float response = (D - m_k * tr * tr);
			if (min > response) min = response;
			if (max < response) max = response;
			pm_response[y*m_width + x] = response;
		}
	}
	cout<<"max="<<max<<", min="<<min<<" "<< endl;
}

vector<Point2i> HarrisDetector::getCorners(float threshold, int wind_n) {
	vector<Point2i> dst = vector<Point2i>();
	Mat temp; 
	nonMaximaSuppresionFloat(m_response, wind_n, temp);
	//normalize(temp,temp,0,255,NORM_L1,CV_8U);
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (temp.at<float>(y,x) > 0.0 && temp.at<float>(y,x) > threshold) {
				dst.push_back(Point2i(x,y));
			}
		}
	}
	cout<<"Dst size = "<<dst.size()<<"\n";
	return dst;
}

Mat HarrisDetector::getResponse() {
	return m_response.clone();
}