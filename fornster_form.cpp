#include "fornster_form.h"
#include "util.h"
#include <qfiledialog.h>
#include <QMessageBox>
#include <qtextcodec.h>
#include <qsizepolicy.h>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

FornsterForm::FornsterForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_image = NULL;

	QTextCodec *langcodec=QTextCodec::codecForName("CP1251");
	QTextCodec::setCodecForLocale(langcodec);

	//ui.labelOriginal->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
	labelCorners = new QLabel;
	labelOriginal = new QLabel;
	labelResponseQ = new QLabel;
	labelResponseW = new QLabel;

	labelOriginal->setScaledContents(true);
	labelCorners->setScaledContents(true);
	labelResponseQ->setScaledContents(true);
	labelResponseW->setScaledContents(true);

	ui.viewTabs->addTab(labelOriginal, "Original");
	ui.viewTabs->addTab(labelCorners, "Corners");
	ui.viewTabs->addTab(labelResponseW, "Response w");
	ui.viewTabs->addTab(labelResponseQ, "Response q");

	//slots connection
	QObject::connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addImages()));
	QObject::connect(ui.removeButton, SIGNAL(clicked()), this, SLOT(removeItem()));
	QObject::connect(ui.fileListWidget, SIGNAL(currentRowChanged(int)), this, SLOT(updateImage()));
	QObject::connect(ui.sliderW, SIGNAL(valueChanged(int)), this, SLOT(slider2spinboxW(int)));
	QObject::connect(ui.sliderQ, SIGNAL(valueChanged(int)), this, SLOT(slider2spinboxQ(int)));
	QObject::connect(ui.spinBoxW, SIGNAL(valueChanged(double)), this, SLOT(spinbox2sliderW(double)));
	QObject::connect(ui.spinBoxQ, SIGNAL(valueChanged(double)), this, SLOT(spinbox2sliderQ(double)));
	QObject::connect(ui.radN1, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.radN2, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.radN3, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.spinBoxQ, SIGNAL(valueChanged(double)), this, SLOT(drawPoints()));
	QObject::connect(ui.spinBoxW, SIGNAL(valueChanged(double)), this, SLOT(drawPoints()));
	//QObject::connect(ui.goButton, SIGNAL(clicked()), this, SLOT(processImages()));
	files.clear();

}

FornsterForm::~FornsterForm()
{

}

void FornsterForm::addImages() {
	QStringList fileNames = QFileDialog::getOpenFileNames(this,
		tr("Open Images"), "",
		tr("Images (*.png *.jpg);;"
		"All Files (*)"));
	if (!fileNames.isEmpty()) {
		//ui.fileListWidget->addItems(fileNames);
		for (QList<QString>::iterator it = fileNames.begin(); it != fileNames.end(); it++) {
			//files.push_back(it->toStdString());
			images.push_back(new TCD::Image(ui.fileListWidget, it->toLocal8Bit().constData()));
			//ui.fileListWidget->addItem(new TCD::Image(ui.fileListWidget, it->toLocal8Bit().constData()));
			
		}
	}
	if (ui.fileListWidget->count() > 0 && ui.fileListWidget->currentRow() == -1) {
		ui.fileListWidget->setCurrentRow(0);
	}
	//update();
}

void FornsterForm::updateImage() {
	try { if (ui.fileListWidget->currentIndex().row() != -1) {
		m_image = (TCD::Image*)ui.fileListWidget->currentItem();
		QString fileName = QString::fromLocal8Bit(m_image->getFilename().data());//ui.fileListWidget->currentItem()->text();
		if (!fileName.isEmpty()) {
			//Mat image_temp = cv::imread(fileName.toStdString(), CV_LOAD_IMAGE_COLOR);
			image.load(fileName);
			if (image.isNull()) {
				QMessageBox::information(this, tr("Image Viewer"),
					tr("Cannot load %1.").arg(fileName));
				return;
			}
			
			//m_image = imread(fileName.toLocal8Bit().constData());

			labelOriginal->setPixmap(QPixmap::fromImage(image));
			labelOriginal->adjustSize();

			drawProcessed();
		}
		}
	} catch(...) {
		throw;
	}
};
void FornsterForm::drawProcessed() {
	if (m_image != NULL) {
		if (ui.radN1->isChecked()) {
			m_image->fornster.init(m_image->getGrayscale(), 0.5);
		} else if (ui.radN2->isChecked()) {
			m_image->fornster.init(m_image->getGrayscale(), 0.7);
		} else if (ui.radN3->isChecked()) {
			m_image->fornster.init(m_image->getGrayscale(), 0.9);
		} 
		drawPoints();
	}

}

void FornsterForm::drawPoints() {
	if (m_image != NULL && m_image->fornster.isDone()) {
		Mat gradient = m_image->getGrayscale();
		Mat responseQ = m_image->fornster.getResponseQ();
		Mat responseW = m_image->fornster.getResponseW();
		normalize(responseQ, responseQ, 0, 255, NORM_MINMAX, CV_8UC1);
		normalize(responseW, responseW, 0, 255, NORM_MINMAX, CV_8UC1);
		labelResponseQ->setPixmap(QPixmap::fromImage(Mat2QImageGrey(responseQ)));
		labelResponseQ->adjustSize();
		labelResponseW->setPixmap(QPixmap::fromImage(Mat2QImageGrey(responseW)));
		labelResponseW->adjustSize();
		int wind_n = 1;
		if (ui.radN1->isChecked()) {
			wind_n = 1;
		} else if (ui.radN2->isChecked()) {
			wind_n = 2;
		} else if (ui.radN3->isChecked()) {
			wind_n = 3;
		} 
		vector<Point2i> points = m_image->fornster.getCorners(ui.spinBoxW->value(), ui.spinBoxQ->value(), 5);
		//harris.getCorners(points);//ui.horizontalSlider->value());
		cvtColor(gradient, gradient, CV_GRAY2RGB);
		for(vector<Point2i>::iterator i = points.begin(); i != points.end(); i++) {
			circle(gradient, *i, 1, Scalar(0,0,255), 2, 8, 0);
		}

		labelCorners->setPixmap(QPixmap::fromImage(Mat2QImageColor(gradient)));
		labelCorners->adjustSize();

	}
}
void FornsterForm::update() {
	ui.fileListWidget->clear();

	for (list<string>::iterator it = files.begin(); it!=files.end(); it++) {
		ui.fileListWidget->addItem(QString::fromStdString(*it));
	}
}

void FornsterForm::removeItem() {
	if (ui.fileListWidget->currentIndex().row() != -1) {
		try {
			files.remove(ui.fileListWidget->currentItem()->text().toLocal8Bit().constData());
			//ui.fileListWidget->removeItemWidget(ui.fileListWidget->currentItem());
			qDeleteAll(ui.fileListWidget->selectedItems());
			//TODO current row change
		} catch(...) {
			throw;
		}
		//update();
	}
}

void FornsterForm::processImages() {
	if (files.size() != 0) {
		

	} else {
		QMessageBox msgBox;
		msgBox.setText("No images to process!");
		msgBox.exec();
	}
}

void FornsterForm::slider2spinboxW(int value) {
	ui.spinBoxW->setValue((double)value/100);
}
void FornsterForm::slider2spinboxQ(int value) {
	ui.spinBoxQ->setValue((double)value/100);
}
void FornsterForm::spinbox2sliderW(double value) {
	ui.sliderW->setValue((int)(value*100));
}
void FornsterForm::spinbox2sliderQ(double value) {
	ui.sliderQ->setValue((int)(value*100));
}
