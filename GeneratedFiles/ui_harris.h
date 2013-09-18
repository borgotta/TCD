/********************************************************************************
** Form generated from reading UI file 'harris.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HARRIS_H
#define UI_HARRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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

class Ui_HarrisForm
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QPushButton *goButton;
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
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HarrisForm)
    {
        if (HarrisForm->objectName().isEmpty())
            HarrisForm->setObjectName(QStringLiteral("HarrisForm"));
        HarrisForm->resize(867, 545);
        actionExit = new QAction(HarrisForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HarrisForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        goButton = new QPushButton(centralWidget);
        goButton->setObjectName(QStringLiteral("goButton"));
        goButton->setGeometry(QRect(40, 470, 141, 31));
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
        horizontalSlider->setMaximum(255);
        horizontalSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(170, 330, 51, 22));
        spinBox->setMaximum(255);
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
        HarrisForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HarrisForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        HarrisForm->setMenuBar(menuBar);
        statusBar = new QStatusBar(HarrisForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HarrisForm->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, goButton);
        QWidget::setTabOrder(goButton, removeButton);
        QWidget::setTabOrder(removeButton, fileListWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(HarrisForm);
        QObject::connect(actionExit, SIGNAL(triggered()), HarrisForm, SLOT(close()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        viewTabs->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(HarrisForm);
    } // setupUi

    void retranslateUi(QMainWindow *HarrisForm)
    {
        HarrisForm->setWindowTitle(QApplication::translate("HarrisForm", "Harris Corner Detector", 0));
        actionExit->setText(QApplication::translate("HarrisForm", "Exit", 0));
        goButton->setText(QApplication::translate("HarrisForm", "Save results", 0));
        addButton->setText(QApplication::translate("HarrisForm", "Add", 0));
        removeButton->setText(QApplication::translate("HarrisForm", "Remove", 0));
        gboxWindow->setTitle(QApplication::translate("HarrisForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("HarrisForm", "2 x 2", 0));
        radN3->setText(QApplication::translate("HarrisForm", "4 x 4", 0));
        radN2->setText(QApplication::translate("HarrisForm", "3 x 3", 0));
        radN4->setText(QApplication::translate("HarrisForm", "5 x 5", 0));
        menuFile->setTitle(QApplication::translate("HarrisForm", "File", 0));
        menuHelp->setTitle(QApplication::translate("HarrisForm", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class HarrisForm: public Ui_HarrisForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARRIS_H
