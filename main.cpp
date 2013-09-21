#include "harris_form.h"
#include "fornster_form.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FornsterForm w;
	w.show();
	return a.exec();
}
