#include "util.h"

void convolveX(std::vector<std::vector<float>>& image,
	const std::vector<float>& filter,
	std::vector<std::vector<float>>& buffer) {
		const int width = image[0].size();
		const int height = image.size();
		const int margin = ((int)filter.size()) / 2;

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				buffer[y][x] = 0.0;

				for (int j = 0; j < (int)filter.size(); ++j) {
					const int xtmp = x + j - margin;
					const int ytmp = y;
					if (xtmp < 0 || width <= xtmp)
						continue;

					buffer[y][x] += filter[j] * image[ytmp][xtmp];
				}
			}
		}

		buffer.swap(image);
}

void convolveY(std::vector<std::vector<float>>& image,
	const std::vector<float>& filter,
	std::vector<std::vector<float>>& buffer) {
		const int width = image[0].size();
		const int height = image.size();
		const int margin = ((int)filter.size()) / 2;

		for (int y = 0; y < height; ++y) {
			for (int x = 0; x < width; ++x) {
				buffer[y][x] = 0.0;

				for (int j = 0; j < (int)filter.size(); ++j) {
					const int xtmp = x;
					const int ytmp = y + j - margin;
					if (ytmp < 0 || height <= ytmp)
						continue;

					buffer[y][x] += filter[j] * image[ytmp][xtmp];
				}
			}
		}

		buffer.swap(image);
}

void convolveX(Mat& src, const std::vector<float>& filter, Mat& dst){
	const int width = src.cols;
	const int height = src.rows;
	const int margin = ((int)filter.size()) / 2;
	src.convertTo(dst, CV_32F); //to float
	Mat result = Mat::zeros(height, width, CV_32F);
	float *data_dst = dst.ptr<float>();
	float *data_result = result.ptr<float>();
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			
			for (int j = 0; j < (int)filter.size(); ++j) {
				const int xtmp = x;
				const int ytmp = y + j - margin;
				if (ytmp < 0 || height <= ytmp)
					continue;

				data_result[y*width + x] += filter[j] * data_dst[ytmp*width + xtmp];
			}
		}
	}
	dst = result;
}
void convolveY(Mat& src, const std::vector<float>& filter, Mat& dst){
	const int width = src.cols;
	const int height = src.rows;
	const int margin = ((int)filter.size()) / 2;
	src.convertTo(dst, CV_32F); //to float
	Mat result = Mat::zeros(height, width, CV_32F);
	float *data_dst = dst.ptr<float>();
	float *data_result = result.ptr<float>();
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			
			for (int j = 0; j < (int)filter.size(); ++j) {
				const int xtmp = x + j - margin;
				const int ytmp = y;
				if (xtmp < 0 || width <= xtmp)
					continue;

				data_result[y*width + x] += filter[j] * data_dst[ytmp*width + xtmp];
			}
		}
	}
	dst = result;
}

QImage Mat2QImageColor(const cv::Mat3b &src) {
	QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
	for (int y = 0; y < src.rows; ++y) {
		const cv::Vec3b *srcrow = src[y];
		QRgb *destrow = (QRgb*)dest.scanLine(y);
		for (int x = 0; x < src.cols; ++x) {
			destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
		}
	}
	return dest;
}


QImage Mat2QImageGrey(const cv::Mat_<uchar> &src)
{
	//double scale = 255.0;
	QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
	for (int y = 0; y < src.rows; ++y) {
		const uchar *srcrow = src[y];
		QRgb *destrow = (QRgb*)dest.scanLine(y);
		for (int x = 0; x < src.cols; ++x) {
			destrow[x] = qRgba(srcrow[x], srcrow[x], srcrow[x], 255);
		}
	}
	return dest;
}

void Mat2Vector(const cv::Mat &src, std::vector<std::vector<float>> &dst) {
	int height = src.rows;
	int width = src.cols;
	dst.clear();
	dst.resize(height);
	for (int i = 0; i < height; i++) {
		dst[i].resize(width);
	}
	uchar *psrc = src.data;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			dst[y][x] = (float)psrc[y*width + x];
		}
	}
}

void hui(cv::Mat &src, float k) {
	uchar* it = src.data;
	for (int y = 0; y < src.rows; y++) 
		for (int x = 0; x < src.cols; x++) {
			it[y*src.cols + x] += (uchar)k;
		}
}

Mat qimage2mat(const QImage& qimage) {
    cv::Mat mat = cv::Mat(qimage.height(), qimage.width(), CV_8UC4, (uchar*)qimage.bits(), qimage.bytesPerLine());
    cv::Mat mat2 = cv::Mat(mat.rows, mat.cols, CV_8UC3 );
    int from_to[] = { 0,0,  1,1,  2,2 };
    cv::mixChannels( &mat, 1, &mat2, 1, from_to, 3 );
    return mat2;
};