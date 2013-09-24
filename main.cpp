#include "harris_form.h"
#include "fornster_form.h"
#include "susan_form.h"
#include "susan_detector.h"
#include <opencv2\highgui\highgui.hpp>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SusanForm w;
	w.show();
	//SusanDetector s;
	//cv::Mat img = cv::imread("images/logo.png");
	//s.init(img, 1);
	//std::cout<<(int)3.4;
	return a.exec();
}
