#include "susan_detector.h"
#include "util.h"
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

SusanDetector::SusanDetector() {};

void SusanDetector::init(Mat image, float t, float radius) { 
	done = false;
	//image.convertTo(m_image, CV_32F);
	//GaussianBlur(image, m_image, Size(), 1.7);
	m_image = image;
	m_t = t;
	m_radius = radius;
	m_height = m_image.rows;
	m_width = m_image.cols;
	initMask();
	setResponse();
	done = true;
}

void SusanDetector::initMask() {
	m_mask.clear();
	int width, height;
	m_y0 = m_x0 = (int)m_radius;
	width = height = ((int)m_radius) * 2 + 1;
	m_mask.resize(height);
	m_m = 0;
	for (int y = 0; y < height; ++y) {
		m_mask[y].resize(width);
		for (int x = 0; x < width; ++x) {
			if (((m_x0 - x) * (m_x0 - x) + (m_y0 - y) * (m_y0 - y)) <= (m_radius * m_radius)) {
				m_mask[y][x] = 1; 
				m_m++;
			} else {
				m_mask[y][x] = 0;
			}
			cout<<(int)m_mask[y][x]<<" ";
		}
		cout<<endl;
	}
}

void SusanDetector::setResponse() {
	
	m_response = Mat::zeros(m_height, m_width, CV_8U);
	uchar* pm_response = m_response.ptr();
	uchar* pm_image = m_image.ptr();
	m_g = ((float)m_m) / 2.0;
	for (int y0 = m_y0; y0 < m_height - (int)m_radius; ++y0) {
		for (int x0 = m_x0; x0 < m_width - (int)m_radius; ++x0) {
			const uchar r0 = pm_image[y0 * m_width + x0];
			int n = 0;
			for (int ry = 0, y = -(int)m_radius; ry < m_mask.size(); ry++, y++) {
				for (int rx = 0, x = -(int)m_radius; rx < m_mask[0].size(); rx++, x++) {
					if (m_mask[ry][rx] && (y != y0 || x != x0)) {
						if ((abs(pm_image[(y0 + y)*m_width + x0 + x] - r0)) <= m_t) {
							n++;
						} 
					} 
				}
			}
			if (n < m_g) {
				pm_response[y0 * m_width + x0] =(uchar) m_g - n;
			}
		}
	}

}

Mat SusanDetector::getResponse() {
	return m_response;
}

vector<Point2i> SusanDetector::getCorners(int threshold, int wind_n) {
	vector<Point2i> dst = vector<Point2i>();
	Mat temp; 
	nonMaximaSuppresionUchar(m_response, wind_n, temp);
	//normalize(temp,temp,0,255,NORM_L1,CV_8U);
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (temp.at<uchar>(y,x) > 0.0 && temp.at<uchar>(y,x) > threshold) {
				dst.push_back(Point2i(x,y));
			}
		}
	}
	cout<<"Dst size = "<<dst.size()<<"\n";
	return dst;
}