#pragma once

#include <opencv2\core\core.hpp>
#include "harris_detector.h"
#include "fornster_detector.h"
#include <qlistwidgetitem>
#include <qlistwidget>


namespace TCD {
	class Image : public QListWidgetItem {
	public: 
		HarrisDetector harris;
		FornsterDetector fornster;

	private:
		std::string filename;

	public:
		Image(QListWidget *view, std::string filename);
		~Image(void);
		std::string getFilename(void);
		cv::Mat getGrayscale(void);
	};
};