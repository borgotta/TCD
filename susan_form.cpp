#include "susan_form.h"
#include "util.h"
#include <qfiledialog.h>
#include <QMessageBox>
#include <qtextcodec.h>
#include <qsizepolicy.h>
#include <opencv2/highgui/highgui.hpp>
#include <Windows.h>
#include <string.h>

using namespace std;
using namespace cv;

SusanForm::SusanForm(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_image = NULL;

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
	QObject::connect(ui.radN1, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.radN2, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.radN3, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.checkBoxSmoothing, SIGNAL(clicked()), this, SLOT(drawProcessed()));
	QObject::connect(ui.spinBoxT, SIGNAL(valueChanged(int)), this, SLOT(drawProcessed()));
	QObject::connect(ui.spinBoxFinalT, SIGNAL(valueChanged(int)), this, SLOT(drawPoints()));
	QObject::connect(this, SIGNAL(progressChanged(int)), ui.progressBar, SLOT(setValue(int)));
	QObject::connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(saveCorners()));
	
	files.clear();

}

SusanForm::~SusanForm()
{

}

void SusanForm::addImages() {
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

void SusanForm::updateImage() {
	try { if (ui.fileListWidget->currentIndex().row() != -1) {
		m_image = (TCD::Image*)ui.fileListWidget->currentItem();
		QString fileName = QString::fromLocal8Bit(m_image->getFilename().data());//ui.fileListWidget->currentItem()->text();
		if (!fileName.isEmpty()) {
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
void SusanForm::drawProcessed() {
	m_image->susan.init(m_image->getGrayscale(), ui.spinBoxT->value(),  ui.checkBoxSmoothing->isChecked());
	drawPoints();
}

void SusanForm::drawPoints() {
	if (m_image != NULL && m_image->susan.isDone()) {
		Mat gradient = m_image->getGrayscale();
		Mat response = m_image->susan.getResponse();

		//normalize(response, responseQ, 0, 255, NORM_MINMAX, CV_8UC1);
		labelResponse->setPixmap(QPixmap::fromImage(Mat2QImageGrey(response)));
		labelResponse->adjustSize();
		int wind_n = 1;
		if (ui.radN1->isChecked()) {
			wind_n = 2;
		} else if (ui.radN2->isChecked()) {
			wind_n = 3;
		} else if (ui.radN3->isChecked()) {
			wind_n = 4;
		} 
		vector<Point2i> points = m_image->susan.getCorners(ui.spinBoxFinalT->value(), wind_n);
		//harris.getCorners(points);//ui.horizontalSlider->value());
		cvtColor(gradient, gradient, CV_GRAY2RGB);
		for(vector<Point2i>::iterator i = points.begin(); i != points.end(); i++) {
			circle(gradient, *i, 1, Scalar(0,0,255), 2, 8, 0);
		}
		ui.labelNCorners->setText(QString::number(points.size()));
		labelCorners->setPixmap(QPixmap::fromImage(Mat2QImageColor(gradient)));
		labelCorners->adjustSize();

	}
}
void SusanForm::update() {
	ui.fileListWidget->clear();

	for (list<string>::iterator it = files.begin(); it!=files.end(); it++) {
		ui.fileListWidget->addItem(QString::fromStdString(*it));
	}
}

void SusanForm::removeItem() {
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

void SusanForm::processImages() {
	if (files.size() != 0) {
		

	} else {
		QMessageBox msgBox;
		msgBox.setText("No images to process!");
		msgBox.exec();
	}
}

void SusanForm::saveCorners() {
	if (ui.fileListWidget->count() < 1) {
		return; 
	} else {
		int n = 0;
		int wind_n = 1;
		if (ui.radN1->isChecked()) {
			wind_n = 2;
		} else if (ui.radN2->isChecked()) {
			wind_n = 3;
		} else if (ui.radN3->isChecked()) {
			wind_n = 4;
		} 
		int total = ui.fileListWidget->count();
		ui.progressBar->setMaximum(total);
		emit progressChanged((n));
		QString folder_name = QFileDialog::getExistingDirectory(this,
		tr("Choose directory"));
		if (!folder_name.isEmpty()) {
			for (int i = 0; i < total; i++) {
				TCD::Image* current = (TCD::Image*)ui.fileListWidget->item(i);
				current->susan.init(current->getGrayscale(), ui.spinBoxT->value(), ui.checkBoxSmoothing->isChecked());
				QFileInfo file(QString::fromLocal8Bit(current->getFilename().data()));
				if (file.exists()) {
					string corners_filename = string(folder_name.toLocal8Bit().data()) + "/SUSAN_" + string(file.baseName().toLocal8Bit().constData()) + ".xml";
					FileStorage fs(corners_filename, FileStorage::WRITE);
					vector<Point2i> points = current->susan.getCorners(ui.spinBoxFinalT->value(), wind_n);
					fs<<"corners"<<"[";
					for(vector<Point2i>::iterator i = points.begin(); i != points.end(); i++) {
						fs<< "{:" << "y" << i->y << "x" << i->x << "}";
					}
					fs<<"]";
					fs.release();
					string response_filename = string(folder_name.toLocal8Bit().data()) + "/SUSAN_" + string(file.baseName().toLocal8Bit().constData()) + ".jpg";
					imwrite(response_filename, current->susan.getResponse());
				}
				progressChanged((++n));
			}
		}
	}
}
