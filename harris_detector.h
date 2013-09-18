#pragma once

#include <opencv2\core\core.hpp>
#include <set>

class HarrisDetector {

public:
	HarrisDetector();
	~HarrisDetector();


	void init(cv::Mat image, float sigma = 1.0);
	cv::Mat getResponse();
	void getCorners(std::vector<cv::Point2i> &dst, float threshold = 0.0, int n = 2);

private:
	int m_height;
	int m_width;
	float m_sigmaD;
	float m_sigmaI;

	cv::Mat m_image;

	std::vector<float> m_gaussD;
	std::vector<float> m_gaussI;

	//std::vector<std::vector<float> > m_dIdx;
	//std::vector<std::vector<float> > m_dIdy;

	//std::vector<std::vector<float> > m_dIdxdIdx;
	//std::vector<std::vector<float> > m_dIdydIdy;
	//std::vector<std::vector<float> > m_dIdxdIdy;

	//std::vector<std::vector<float> > m_response;
	
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
