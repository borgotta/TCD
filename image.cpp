#include "image.h"
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2\imgproc\imgproc.hpp>

using namespace TCD;
using namespace std;
using namespace cv;

Image::Image(string filename) { 
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
void Image::runHarris() {
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
		harris.init(m_image);
		m_response = harris.getResponse();
		harris.getCorners(corners);
	} catch(...) {
		harrisDone = false; 
		cerr<<"Harris: error detecting corners\n";
		return;
	}
	harrisDone = true;
}