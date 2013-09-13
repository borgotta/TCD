#include "choice.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Choice w;
	w.show();
	return a.exec();
}
