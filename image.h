#pragma once

#include <opencv2\core\core.hpp>
#include "harris_detector.h"


namespace TCD {
	class Image {
	public: 
		cv::Mat m_response; 

	private:
		std::string filename;
		HarrisDetector harris;
		bool harrisDone;
		std::vector<cv::Point2i> corners;

	public:
		Image(std::string filename);
		~Image(void);
		void runHarris(void);
		bool isHarrisDone(void);
		std::string getFilename(void);
		std::vector<cv::Point2i> getCorners(void);
	};
};