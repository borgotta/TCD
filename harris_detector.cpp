#include "harris_detector.h"
#include "util.h"

using namespace std;
using namespace cv;


HarrisDetector::HarrisDetector() {}
HarrisDetector::~HarrisDetector() {}
void HarrisDetector::init(Mat image) {
	m_image = image;	
	m_height = m_image.rows;
	m_width = m_image.cols;
	m_sigmaD = 1.4;
	m_sigmaI = 1.4;
	setGaussD(m_sigmaD, m_gaussD);
	setGaussI(m_sigmaI, m_gaussI); 
	setDerivatives();
	setResponse();
}

void HarrisDetector::setDerivatives() {
	preprocess();
	preprocess2();
}

void HarrisDetector::preprocess() {
	m_image.copyTo(m_dIdx);
	//m_dIdx = m_image;

	vector<float> dfilter, ifilter;
	dfilter.resize(3);
	dfilter[0] = -0.5;  dfilter[1] = 0;  dfilter[2] = 0.5;
	ifilter.resize(3);
	ifilter[0] = 1.0 / 3.0;  ifilter[1] = 1.0 / 3.0;  ifilter[2] = 1.0 / 3.0;

	convolveX(m_dIdx, dfilter, m_dIdx);
	convolveY(m_dIdx, ifilter, m_dIdx);

	m_image.copyTo(m_dIdy);
	//m_dIdy = m_image;

	convolveX(m_dIdy, ifilter, m_dIdy);
	convolveY(m_dIdy, dfilter, m_dIdy);
}

void HarrisDetector::preprocess2() {
	m_dIdxdIdx = Mat::zeros(m_height, m_width, CV_32F);  
	m_dIdydIdy = Mat::zeros(m_height, m_width, CV_32F);
	m_dIdxdIdy = Mat::zeros(m_height, m_width, CV_32F);

	float *pm_dIdxdIdx = m_dIdxdIdx.ptr<float>();
	float *pm_dIdydIdy = m_dIdxdIdx.ptr<float>();
	float *pm_dIdxdIdy = m_dIdxdIdx.ptr<float>();
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
  convolveX(m_dIdxdIdx, m_gaussI, m_dIdxdIdx);
  convolveY(m_dIdxdIdx, m_gaussI, m_dIdxdIdx);
  
  //----------------------------------------------------------------------
  // m_dIdydIdy
  convolveX(m_dIdydIdy, m_gaussI, m_dIdydIdy);
  convolveY(m_dIdydIdy, m_gaussI, m_dIdydIdy);
  
  //----------------------------------------------------------------------
  // m_dIdxdIdy
  convolveX(m_dIdxdIdy, m_gaussI, m_dIdxdIdy);
  convolveY(m_dIdxdIdy, m_gaussI, m_dIdxdIdy);
}

void HarrisDetector::setGaussD(const float sigmaD, std::vector<float>& gaussD) {
	//----------------------------------------------------------------------  
	const int marginD = (int)ceil(2 * sigmaD);
	const int sizeD = 2 * marginD + 1;

	gaussD.resize(sizeD);

	//----------------------------------------------------------------------
	// set m_gaussD
	float denom = 0.0;
	for (int x = 0; x < sizeD; ++x) {
		int xtmp = x - marginD;
		const float dtmp = xtmp * exp(- (xtmp * xtmp) / (2 * sigmaD * sigmaD));
		gaussD[x] = dtmp;
		if (0.0 < dtmp)
			denom += dtmp;
	}

	for (int x = 0; x < sizeD; ++x)
		gaussD[x] /= denom;
}

void HarrisDetector::setGaussI(const float sigmaI, std::vector<float>& gaussI) {
	const int marginI = (int)ceil(2 * sigmaI);
	const int sizeI = 2 * marginI + 1;

	gaussI.resize(sizeI);

	//----------------------------------------------------------------------
	// set m_gaussI
	float denom = 0.0;
	for (int x = 0; x < sizeI; ++x) {
		int xtmp = x - marginI;
		const float dtmp = exp(- (xtmp * xtmp) / (2 * sigmaI * sigmaI));
		gaussI[x] = dtmp;
		denom += dtmp;
	}
	for (int x = 0; x < sizeI; ++x)
		gaussI[x] /= denom;
}

Mat HarrisDetector::getResponse() {
	return m_response;
}

void HarrisDetector::setResponse() {
	m_response = Mat::zeros(m_height, m_width, CV_32F);
	float *pm_response = m_response.ptr<float>();
	for (int y = 0; y < m_height; ++y) {
		for (int x = 0; x < m_width; ++x) {
			const float D = m_dIdxdIdx.at<float>(y,x) * m_dIdydIdy.at<float>(y,x) - m_dIdxdIdy.at<float>(y,x) * m_dIdxdIdy.at<float>(y,x);
			const float tr = m_dIdxdIdx.at<float>(y,x) + m_dIdydIdy.at<float>(y,x);
			pm_response[y*m_width + x] = D - 0.06 * tr * tr;
		}
	}
}
void HarrisDetector::getCorners(vector<Point2i> &dst, float threshold) {
	//----------------------------------------------------------------------
	// suppress non local max
	Mat temp = Mat::zeros(m_height, m_width, CV_32F);
	//m_response.copyTo(temp);
	float *ptemp = temp.ptr<float>();
	for (int y = 1; y < m_height - 1; ++y) {
		for (int x = 1; x < m_width - 1; ++x) {
			if (m_response.at<float>(y,x) >= m_response.at<float>(y,x+1) &&
				m_response.at<float>(y,x) >= m_response.at<float>(y,x-1) &&
				m_response.at<float>(y,x) >= m_response.at<float>(y+1,x) &&
				m_response.at<float>(y,x) >= m_response.at<float>(y-1,x))
				ptemp[y*m_width + x] = m_response.at<float>(y,x);
		}
	}
	//normalize(temp,temp,0,255,NORM_MINMAX,CV_8U);
	dst = vector<Point2i>();
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (temp.at<float>(y,x) > 0 && temp.at<float>(y,x) > threshold) {
				dst.push_back(Point2i(x,y));
			}
		}
	}
	cout<<"Dst size = "<<dst.size()<<"\n";
}	