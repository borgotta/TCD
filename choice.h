#pragma once

#include <QtWidgets/qwidget.h>
#include "ui_choice_form.h"
#include "harris_form.h"
#include <set>

class Choice : public QWidget
{
	Q_OBJECT

private slots:
	void goToHarris();

public:
	Choice(QWidget *parent = 0);
	~Choice();

private:
	Ui::Form ui;
	HarrisForm* harris;

};
