/********************************************************************************
** Form generated from reading UI file 'fornster_form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORNSTER_FORM_H
#define UI_FORNSTER_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FornsterForm
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QTabWidget *viewTabs;
    QListWidget *fileListWidget;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;
    QGroupBox *gboxWindow;
    QRadioButton *radN1;
    QRadioButton *radN3;
    QRadioButton *radN2;
    QRadioButton *radN4;
    QDoubleSpinBox *spinBoxW;
    QDoubleSpinBox *spinBoxQ;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FornsterForm)
    {
        if (FornsterForm->objectName().isEmpty())
            FornsterForm->setObjectName(QStringLiteral("FornsterForm"));
        FornsterForm->resize(867, 545);
        actionExit = new QAction(FornsterForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(FornsterForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 280, 182, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(30);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(layoutWidget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(layoutWidget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(240, 10, 611, 491));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(20);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        viewTabs = new QTabWidget(layoutWidget1);
        viewTabs->setObjectName(QStringLiteral("viewTabs"));

        verticalLayout->addWidget(viewTabs);

        fileListWidget = new QListWidget(centralWidget);
        fileListWidget->setObjectName(QStringLiteral("fileListWidget"));
        fileListWidget->setGeometry(QRect(10, 10, 211, 261));
        fileListWidget->setDragEnabled(false);
        fileListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fileListWidget->setTextElideMode(Qt::ElideRight);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 330, 141, 22));
        horizontalSlider->setMaximum(2000);
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(170, 330, 51, 22));
        spinBox->setMaximum(2000);
        gboxWindow = new QGroupBox(centralWidget);
        gboxWindow->setObjectName(QStringLiteral("gboxWindow"));
        gboxWindow->setGeometry(QRect(20, 360, 171, 101));
        gboxWindow->setAutoFillBackground(true);
        radN1 = new QRadioButton(gboxWindow);
        radN1->setObjectName(QStringLiteral("radN1"));
        radN1->setGeometry(QRect(10, 20, 82, 17));
        radN1->setChecked(true);
        radN3 = new QRadioButton(gboxWindow);
        radN3->setObjectName(QStringLiteral("radN3"));
        radN3->setGeometry(QRect(10, 60, 82, 17));
        radN2 = new QRadioButton(gboxWindow);
        radN2->setObjectName(QStringLiteral("radN2"));
        radN2->setGeometry(QRect(10, 40, 82, 17));
        radN4 = new QRadioButton(gboxWindow);
        radN4->setObjectName(QStringLiteral("radN4"));
        radN4->setGeometry(QRect(10, 80, 82, 17));
        spinBoxW = new QDoubleSpinBox(centralWidget);
        spinBoxW->setObjectName(QStringLiteral("spinBoxW"));
        spinBoxW->setGeometry(QRect(30, 470, 62, 22));
        spinBoxW->setMinimum(0.05);
        spinBoxW->setMaximum(1.5);
        spinBoxW->setSingleStep(0.01);
        spinBoxW->setValue(0.5);
        spinBoxQ = new QDoubleSpinBox(centralWidget);
        spinBoxQ->setObjectName(QStringLiteral("spinBoxQ"));
        spinBoxQ->setGeometry(QRect(120, 470, 62, 22));
        spinBoxQ->setMinimum(0.5);
        spinBoxQ->setMaximum(0.75);
        FornsterForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FornsterForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        FornsterForm->setMenuBar(menuBar);
        statusBar = new QStatusBar(FornsterForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FornsterForm->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, fileListWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(FornsterForm);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        viewTabs->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FornsterForm);
    } // setupUi

    void retranslateUi(QMainWindow *FornsterForm)
    {
        FornsterForm->setWindowTitle(QApplication::translate("FornsterForm", "Fornster Corner Detector", 0));
        actionExit->setText(QApplication::translate("FornsterForm", "Exit", 0));
        addButton->setText(QApplication::translate("FornsterForm", "Add", 0));
        removeButton->setText(QApplication::translate("FornsterForm", "Remove", 0));
        gboxWindow->setTitle(QApplication::translate("FornsterForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("FornsterForm", "2 x 2", 0));
        radN3->setText(QApplication::translate("FornsterForm", "4 x 4", 0));
        radN2->setText(QApplication::translate("FornsterForm", "3 x 3", 0));
        radN4->setText(QApplication::translate("FornsterForm", "5 x 5", 0));
        menuFile->setTitle(QApplication::translate("FornsterForm", "File", 0));
        menuHelp->setTitle(QApplication::translate("FornsterForm", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class FornsterForm: public Ui_FornsterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORNSTER_FORM_H
