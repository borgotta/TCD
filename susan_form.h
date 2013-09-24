#pragma once

#include <QtWidgets/QMainWindow>
#include <qlabel.h>
#include "ui_susan_form.h"
#include <list>
#include "image.h"

class SusanForm : public QMainWindow
{
	Q_OBJECT

private slots:
	void addImages();
	void updateImage();
	void drawProcessed();
	void drawPoints();
	void removeItem();
	void update();
	void processImages();

public:
	SusanForm(QWidget *parent = 0);
	~SusanForm();

private:
	Ui::SusanForm ui;
	std::list<std::string> files;
	std::vector<TCD::Image*> images;
	QLabel *labelOriginal;
	QLabel *labelResponse;
	QLabel *labelCorners;
	QImage image;
	TCD::Image *m_image;
};