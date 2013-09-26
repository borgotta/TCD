#pragma once

#include <QtWidgets/QMainWindow>
#include <qlabel.h>
#include "ui_fornster_form.h"
#include <list>
#include "image.h"

class FornsterForm : public QMainWindow
{
	Q_OBJECT

private slots:
	void addImages();
	void updateImage();
	void drawProcessed();
	void drawPoints();
	void removeItem();
	void slider2spinboxW(int value);
	void slider2spinboxQ(int value);
	void spinbox2sliderW(double value);
	void spinbox2sliderQ(double value);
	void saveCorners();

signals:
	void progressChanged(int n);
public:
	FornsterForm(QWidget *parent = 0);
	~FornsterForm();

private:
	Ui::FornsterForm ui;
	std::list<std::string> files;
	std::vector<TCD::Image*> images;
	QLabel *labelOriginal;
	QLabel *labelResponseW;
	QLabel *labelResponseQ;
	QLabel *labelCorners;
	QImage image;
	TCD::Image *m_image;
};