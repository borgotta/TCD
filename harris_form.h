#pragma once

#include <QtWidgets/QMainWindow>
#include <qlabel.h>
#include "ui_harris.h"
#include "harris_detector.h"
#include <list>
#include <opencv2\core\core.hpp>
#include "image.h"

class HarrisForm : public QMainWindow
{
	Q_OBJECT

private slots:
	void addImages();
	void updateImage();
	void updateProcessed();
	void removeItem();
	void update();
	void processImages();

public:
	HarrisForm(QWidget *parent = 0);
	~HarrisForm();

private:
	Ui::HarrisForm ui;
	HarrisDetector harris;
	std::list<std::string> files;
	std::vector<TCD::Image> images;
	QLabel *labelOriginal;
	QLabel *labelResponse;
	QLabel *labelCorners;
	QImage image;
	cv::Mat m_image;
};