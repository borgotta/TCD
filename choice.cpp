#include "choice.h"
#include <qfiledialog.h>
#include <QMessageBox>

using namespace std;

Choice::Choice(QWidget *parent)
	: QWidget(parent) {
		ui.setupUi(this);

		//connects
		QObject::connect(ui.btnToHarris, SIGNAL(clicked()), this, SLOT(goToHarris()));
}
Choice::~Choice() {

}
void Choice::goToHarris() {
	harris = new HarrisForm();
	harris->show();
	hide();
}