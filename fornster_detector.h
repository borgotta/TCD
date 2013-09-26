#pragma once

#include "detector.h"

class FornsterDetector : public TCD::Detector {
	
	
public:
	FornsterDetector();
	virtual ~FornsterDetector(){}
	std::vector<cv::Point2i> getCorners(float w = 0.5, float q = 0.5, int wind_n = 3);
	void init(cv::Mat image, float sigma = 0.7, bool smooth = false);
	cv::Mat getResponseW();
	cv::Mat getResponseQ();

private:
	void setDerivatives();
	void preprocess();
	void preprocess2();
	void setResponse();

	cv::Mat m_dIdx;
	cv::Mat m_dIdy;

	cv::Mat m_dIdxdIdx;
	cv::Mat m_dIdydIdy;
	cv::Mat m_dIdxdIdy;

	cv::Mat m_wResponse;
	cv::Mat m_qResponse;

	float m_w;
};