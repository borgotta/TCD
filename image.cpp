#include "image.h"
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2\imgproc\imgproc.hpp>

using namespace TCD;
using namespace std;
using namespace cv;

Image::Image(QListWidget *view, string filename) : QListWidgetItem(QString::fromLocal8Bit(filename.data(), filename.size()), view, 1000) { //1000 is a user type
	Image::filename = filename;
}

Image::~Image() {}

string Image::getFilename() {
	return filename;
}

Mat TCD::Image::getGrayscale() {
	if (filename.size() > 0) {
		return imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
	} else {
		cerr<<"getGrayscale() - error openning file"<<endl;
		return Mat();
	}
}
