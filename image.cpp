#include "image.h"
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2\imgproc\imgproc.hpp>

using namespace TCD;
using namespace std;
using namespace cv;

Image::Image(QListWidget *view, string filename) : QListWidgetItem(QString::fromLocal8Bit(filename.data(), filename.size()), view, 1000) { //1000 is a user type

	Image::filename = filename;
	harrisDone = false;
}

Image::~Image() {}

string Image::getFilename() {
	return filename;
}

bool Image::isHarrisDone() {
	return harrisDone;
}
void Image::runHarris(float sigma) {
	Mat m_image; //grayscale
	try {
		m_image = imread(filename);
		cvtColor(m_image, m_image, CV_BGR2GRAY);
	} catch(...) {
		harrisDone = false;
		cerr<<"Harris: couldn't open file\n";
		return;
	}
	try {
		harris.init(m_image, sigma);
		m_response = harris.getResponse();
		//harris.getCorners(corners, threshold);
	} catch(...) {
		harrisDone = false; 
		cerr<<"Harris: error detecting corners\n";
		return;
	}
	harrisDone = true;
}

Mat TCD::Image::getGrayscale() {
	if (filename.size() > 0) {
		return imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	} else {
		cerr<<"getGrayscale() - error openning file"<<endl;
		return Mat();
	}
}

vector<Point2i> TCD::Image::getCorners(float threshold) {
	harris.getCorners(corners, threshold);
	return corners;
}