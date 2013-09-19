#pragma once

#include <opencv2\core\core.hpp>
#include "harris_detector.h"
#include <qlistwidgetitem>
#include <qlistwidget>


namespace TCD {
	class Image : public QListWidgetItem {
	public: 
		cv::Mat m_response; 

	private:
		std::string filename;
		HarrisDetector harris;
		bool harrisDone;
		std::vector<cv::Point2i> corners;

	public:
		Image(QListWidget *view, std::string filename);
		~Image(void);
		void runHarris(float sigma = 0.7, float k = 0.4);
		bool isHarrisDone(void);
		std::string getFilename(void);
		std::vector<cv::Point2i> getCorners(float threshold = 0.0, int wind_n = 2);
		cv::Mat getGrayscale(void);
	};
};