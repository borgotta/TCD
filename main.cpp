#include "harris_form.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HarrisForm w;
	w.show();
	return a.exec();
}
