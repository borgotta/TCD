#include "susan_detector.h"
#include "util.h"
#include <opencv2\imgproc\imgproc.hpp>

using namespace std;
using namespace cv;

SusanDetector::SusanDetector() {};

void SusanDetector::init(Mat image, float t, bool useSmoothing) { 
	done = false;
	//image.convertTo(m_image, CV_32F);
	if (useSmoothing) {
		medianBlur(image, m_image, 5);
	} else {
		m_image = image;
	}
	m_t = t;
	m_radius = 3.4;
	m_height = m_image.rows;
	m_width = m_image.cols;
	max_no_corners = 1850;
	//initMask();
	setupBrightnessLut(&m_bp);
	setResponseOriginal();
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

void SusanDetector::setResponseOriginal() {
	m_response = Mat::zeros(m_height, m_width, CV_32S);
	int *r = m_response.ptr<int>(); //response
	uchar *in = m_image.ptr();
	int   n,x,y,sq,xx,yy,
		i,j,*cgx,*cgy;
	float divide;
	uchar c,*p,*cp;

	memset (r,0,m_width * m_height * sizeof(int));

	cgx=(int *)malloc(m_width*m_height*sizeof(int));
	cgy=(int *)malloc(m_width*m_height*sizeof(int));

	for (i=5;i<m_height-5;i++)
		for (j=5;j<m_width-5;j++) {
			n=100;
			p=in + (i-3)*m_width + j - 1;
			cp=m_bp + in[i*m_width+j];

			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p);
			p+=m_width-3; 

			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p);
			p+=m_width-5;

			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p);
			p+=m_width-6;

			n+=*(cp-*p++);
			n+=*(cp-*p++);
			n+=*(cp-*p);
			if (n<max_no_corners){    /* do this test early and often ONLY to save wasted computation */
				p+=2;
				n+=*(cp-*p++);
				if (n<max_no_corners){
					n+=*(cp-*p++);
					if (n<max_no_corners){
						n+=*(cp-*p);
						if (n<max_no_corners){
							p+=m_width-6;

							n+=*(cp-*p++);
							if (n<max_no_corners){
								n+=*(cp-*p++);
								if (n<max_no_corners){
									n+=*(cp-*p++);
									if (n<max_no_corners){
										n+=*(cp-*p++);
										if (n<max_no_corners){
											n+=*(cp-*p++);
											if (n<max_no_corners){
												n+=*(cp-*p++);
												if (n<max_no_corners){
													n+=*(cp-*p);
													if (n<max_no_corners){
														p+=m_width-5;

														n+=*(cp-*p++);
														if (n<max_no_corners){
															n+=*(cp-*p++);
															if (n<max_no_corners){
																n+=*(cp-*p++);
																if (n<max_no_corners){
																	n+=*(cp-*p++);
																	if (n<max_no_corners){
																		n+=*(cp-*p);
																		if (n<max_no_corners){
																			p+=m_width-3;

																			n+=*(cp-*p++);
																			if (n<max_no_corners){
																				n+=*(cp-*p++);
																				if (n<max_no_corners){
																					n+=*(cp-*p);

																					if (n<max_no_corners)
																					{
																						x=0;y=0;
																						p=in + (i-3)*m_width + j - 1;

																						c=*(cp-*p++);x-=c;y-=3*c;
																						c=*(cp-*p++);y-=3*c;
																						c=*(cp-*p);x+=c;y-=3*c;
																						p+=m_width-3; 

																						c=*(cp-*p++);x-=2*c;y-=2*c;
																						c=*(cp-*p++);x-=c;y-=2*c;
																						c=*(cp-*p++);y-=2*c;
																						c=*(cp-*p++);x+=c;y-=2*c;
																						c=*(cp-*p);x+=2*c;y-=2*c;
																						p+=m_width-5;

																						c=*(cp-*p++);x-=3*c;y-=c;
																						c=*(cp-*p++);x-=2*c;y-=c;
																						c=*(cp-*p++);x-=c;y-=c;
																						c=*(cp-*p++);y-=c;
																						c=*(cp-*p++);x+=c;y-=c;
																						c=*(cp-*p++);x+=2*c;y-=c;
																						c=*(cp-*p);x+=3*c;y-=c;
																						p+=m_width-6;

																						c=*(cp-*p++);x-=3*c;
																						c=*(cp-*p++);x-=2*c;
																						c=*(cp-*p);x-=c;
																						p+=2;
																						c=*(cp-*p++);x+=c;
																						c=*(cp-*p++);x+=2*c;
																						c=*(cp-*p);x+=3*c;
																						p+=m_width-6;

																						c=*(cp-*p++);x-=3*c;y+=c;
																						c=*(cp-*p++);x-=2*c;y+=c;
																						c=*(cp-*p++);x-=c;y+=c;
																						c=*(cp-*p++);y+=c;
																						c=*(cp-*p++);x+=c;y+=c;
																						c=*(cp-*p++);x+=2*c;y+=c;
																						c=*(cp-*p);x+=3*c;y+=c;
																						p+=m_width-5;

																						c=*(cp-*p++);x-=2*c;y+=2*c;
																						c=*(cp-*p++);x-=c;y+=2*c;
																						c=*(cp-*p++);y+=2*c;
																						c=*(cp-*p++);x+=c;y+=2*c;
																						c=*(cp-*p);x+=2*c;y+=2*c;
																						p+=m_width-3;

																						c=*(cp-*p++);x-=c;y+=3*c;
																						c=*(cp-*p++);y+=3*c;
																						c=*(cp-*p);x+=c;y+=3*c;

																						xx=x*x;
																						yy=y*y;
																						sq=xx+yy;
																						if ( sq > ((n*n)/2) )
																						{
																							if(yy<xx) {
																								divide=(float)y/(float)abs(x);
																								sq=abs(x)/x;
																								sq=*(cp-in[(i+static_cast<int>(divide))*m_width+j+sq]) +
																									*(cp-in[(i+static_cast<int>(2*divide))*m_width+j+2*sq]) +
																									*(cp-in[(i+static_cast<int>(3*divide))*m_width+j+3*sq]);}
																							else {
																								divide=(float)x/(float)abs(y);
																								sq=abs(y)/y;
																								sq=*(cp-in[(i+sq)*m_width+j+static_cast<int>(divide)]) +
																									*(cp-in[(i+2*sq)*m_width+j+static_cast<int>(2*divide)]) +
																									*(cp-in[(i+3*sq)*m_width+j+static_cast<int>(3*divide)]);}

																							if(sq>290){
																								r[i*m_width+j] = max_no_corners-n;
																								cgx[i*m_width+j] = (51*x)/n;
																								cgy[i*m_width+j] = (51*y)/n;}
																						}
																					}
																				}}}}}}}}}}}}}}}}}}}
																				free(cgx);
																				free(cgy);
}

Mat SusanDetector::getResponse() {
	return m_response;
}

vector<Point2i> SusanDetector::getCorners(int threshold, int wind_n) {
	vector<Point2i> dst = vector<Point2i>();
	Mat temp; 
	nonMaximaSuppresionInt(m_response, wind_n, temp);
	//normalize(temp,temp,0,255,NORM_L1,CV_8U);
	for (int y = 0; y < m_height; y++) {
		for (int x = 0; x < m_width; x++) {
			if (temp.at<int>(y,x) > 0.0 && temp.at<int>(y,x) > threshold) {
				dst.push_back(Point2i(x,y));
			}
		}
	}
	cout<<"Dst size = "<<dst.size()<<"\n";
	return dst;
}

/*
	Original implementation
*/
void SusanDetector::setupBrightnessLut(uchar **bp) {
	int   k;
	float temp;

	*bp=(uchar *)malloc(516);
	*bp=*bp+258;

	for(k=-256;k<257;k++)
	{
		temp=((float)k)/((float)m_t);
		temp=temp*temp;
		temp=temp*temp*temp;
		temp=100.0*exp(-temp);
		*(*bp+k)= (uchar)temp;
	}
}