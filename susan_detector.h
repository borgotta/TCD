#pragma once

#include "detector.h"

class SusanDetector : public TCD::Detector {
	
public:
	SusanDetector();
	virtual ~SusanDetector(){}
	std::vector<cv::Point2i> getCorners(int threshold = 0, int wind_n = 2);
	void init(cv::Mat image, float t, float radius = 3.4);
	cv::Mat getResponse();

private:
	void initMask();
	void setResponse();
	
	std::vector<std::vector<uchar>> m_mask;
	cv::Mat m_response;
	int m_y0, m_x0; //nucleus
	float m_radius;
	int m_m; //number of pixels in USAN
	float m_t; //threshold
	float m_g; //geometric threshold
};