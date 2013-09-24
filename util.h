#pragma once

#include <vector>
#include <opencv2\core\core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <qimage.h>

using namespace std;
using namespace cv;

void setGaussD(const float sigmaD, std::vector<float>& gaussD);
void setGaussI(const float sigmaI, std::vector<float>& gaussI);
void nonMaximaSuppresionFloat(Mat &src, int n, Mat &dst);
void nonMaximaSuppresionUchar(Mat &src, int n, Mat &dst);
void convolveX(Mat& src, const std::vector<float>& filter, Mat& dst);
void convolveY(Mat& src, const std::vector<float>& filter, Mat& dst);

QImage Mat2QImageColor(const cv::Mat3b &src);
QImage Mat2QImageGrey(const cv::Mat_<uchar> &src);

void Mat2Vector(const cv::Mat &src, std::vector<std::vector<float>> &dst);

void hui(cv::Mat &src, float k) ;

cv::Mat qimage2mat(const QImage& qimage);