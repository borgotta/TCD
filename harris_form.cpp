#include "harris_form.h"
#include "util.h"
#include <qfiledialog.h>
#include <QMessageBox>
#include <qtextcodec.h>
#include <qsizepolicy.h>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

HarrisForm::HarrisForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	QTextCodec *langcodec=QTextCodec::codecForName("CP1251");
	QTextCodec::setCodecForLocale(langcodec);

	//ui.labelOriginal->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
	labelCorners = new QLabel;
	labelOriginal = new QLabel;
	labelResponse = new QLabel;

	labelOriginal->setScaledContents(true);
	labelCorners->setScaledContents(true);
	labelResponse->setScaledContents(true);

	ui.viewTabs->addTab(labelOriginal, "Original");
	ui.viewTabs->addTab(labelCorners, "Corners");
	ui.viewTabs->addTab(labelResponse, "Response");

	//slots connection
	QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addImages()));
	QObject::connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeItem()));
	QObject::connect(ui.fileListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(updateImage()));
	QObject::connect(ui.horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(updateProcessed()));
	QObject::connect(ui.goButton, SIGNAL(clicked()), this, SLOT(processImages()));


	files.clear();

}

HarrisForm::~HarrisForm()
{

}

void HarrisForm::addImages() {
	QStringList fileNames = QFileDialog::getOpenFileNames(this,
		tr("Open Images"), "",
		tr("Images (*.png *.jpg);;"
		"All Files (*)"));
	if (!fileNames.isEmpty()) {
		//ui.fileListWidget->addItems(fileNames);
		for (QList<QString>::iterator it = fileNames.begin(); it != fileNames.end(); it++) {
			files.push_back(it->toStdString());
			images.push_back(TCD::Image(it->toLocal8Bit().constData()));
		}
	}
	update();
}

void HarrisForm::updateImage() {
	try { if (ui.fileListWidget->currentIndex().row() != -1) {
		QString fileName = ui.fileListWidget->currentItem()->text();
		if (!fileName.isEmpty()) {
			//Mat image_temp = cv::imread(fileName.toStdString(), CV_LOAD_IMAGE_COLOR);
			image.load(fileName);
			if (image.isNull()) {
				QMessageBox::information(this, tr("Image Viewer"),
					tr("Cannot load %1.").arg(fileName));
				return;
			}
			
			m_image = imread(fileName.toLocal8Bit().constData());

			labelOriginal->setPixmap(QPixmap::fromImage(image));
			labelOriginal->adjustSize();

			updateProcessed();
		}
		}
	} catch(...) {
		throw;
	}
};
void HarrisForm::updateProcessed() {
	if (!m_image.empty()) {
		Mat gradient;
		cvtColor(m_image, gradient, CV_BGR2GRAY);
		harris.init(gradient);
		Mat response = harris.getResponse();

		normalize(response, response, 0, 255, NORM_MINMAX, CV_8UC1);
		labelResponse->setPixmap(QPixmap::fromImage(Mat2QImageGrey(response)));
		labelResponse->adjustSize();

		Mat circles;
		cvtColor(m_image, circles, CV_BGR2GRAY);
		vector<Point2i> points;
		harris.getCorners(points);//ui.horizontalSlider->value());
		for(vector<Point2i>::iterator i = points.begin(); i != points.end(); i++) {
			circle(circles, *i, 1, Scalar(0,0,255), 1, 8, 0);
		}
		
		labelCorners->setPixmap(QPixmap::fromImage(Mat2QImageGrey(circles)));
		labelCorners->adjustSize();
	}
}

void HarrisForm::update() {
	ui.fileListWidget->clear();

	for (list<string>::iterator it = files.begin(); it!=files.end(); it++) {
		ui.fileListWidget->addItem(QString::fromStdString(*it));
	}
}

void HarrisForm::removeItem() {
	if (ui.fileListWidget->currentIndex().row() != -1) {
		try {
			files.remove(ui.fileListWidget->currentItem()->text().toLocal8Bit().constData());
			//ui.fileListWidget->removeItemWidget(ui.fileListWidget->currentItem());
			qDeleteAll(ui.fileListWidget->selectedItems());
		} catch(...) {
			throw;
		}
		//update();
	}
}

void HarrisForm::processImages() {
	if (files.size() != 0) {
		

	} else {
		QMessageBox msgBox;
		msgBox.setText("No images to process!");
		msgBox.exec();
	}
}
