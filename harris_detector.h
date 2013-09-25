#pragma once

#include "detector.h"
#include <opencv2\core\core.hpp>
#include <set>

class HarrisDetector : public TCD::Detector {

public:
	HarrisDetector();
	~HarrisDetector();

	cv::Mat getResponse();
	void init(cv::Mat image, float sigma = 1.0, float k = 0.4, bool smoothBefore = false);
	std::vector<cv::Point2i> getCorners(float threshold = 0.0, int n = 2);

private:
	float m_k;
	
	cv::Mat m_dIdx;
	cv::Mat m_dIdy;

	cv::Mat m_dIdxdIdx;
	cv::Mat m_dIdydIdy;
	cv::Mat m_dIdxdIdy;
	
	cv::Mat m_response;

	void setDerivatives();
	void setResponse();
	void preprocess();
	void preprocess2();
};
