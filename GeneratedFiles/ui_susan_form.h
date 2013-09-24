/********************************************************************************
** Form generated from reading UI file 'susan_form.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSAN_FORM_H
#define UI_SUSAN_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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

class Ui_SusanForm
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QListWidget *fileListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QGridLayout *gridLayout;
    QSlider *sliderT;
    QSlider *sliderW;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxT;
    QSpinBox *spinBoxFinalT;
    QGroupBox *gboxWindow;
    QRadioButton *radN1;
    QRadioButton *radN3;
    QRadioButton *radN2;
    QTabWidget *viewTabs;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SusanForm)
    {
        if (SusanForm->objectName().isEmpty())
            SusanForm->setObjectName(QStringLiteral("SusanForm"));
        SusanForm->resize(903, 568);
        actionExit = new QAction(SusanForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(SusanForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(281, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        fileListWidget = new QListWidget(widget);
        fileListWidget->setObjectName(QStringLiteral("fileListWidget"));
        fileListWidget->setDragEnabled(false);
        fileListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fileListWidget->setTextElideMode(Qt::ElideRight);

        verticalLayout->addWidget(fileListWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addButton = new QPushButton(widget);
        addButton->setObjectName(QStringLiteral("addButton"));

        horizontalLayout->addWidget(addButton);

        removeButton = new QPushButton(widget);
        removeButton->setObjectName(QStringLiteral("removeButton"));

        horizontalLayout->addWidget(removeButton);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(6);
        sliderT = new QSlider(widget);
        sliderT->setObjectName(QStringLiteral("sliderT"));
        sliderT->setMaximumSize(QSize(185, 22));
        sliderT->setMinimum(0);
        sliderT->setMaximum(254);
        sliderT->setValue(10);
        sliderT->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderT, 0, 0, 1, 1);

        sliderW = new QSlider(widget);
        sliderW->setObjectName(QStringLiteral("sliderW"));
        sliderW->setMaximumSize(QSize(16777215, 22));
        sliderW->setMinimum(0);
        sliderW->setMaximum(99);
        sliderW->setValue(0);
        sliderW->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderW, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        spinBoxT = new QSpinBox(widget);
        spinBoxT->setObjectName(QStringLiteral("spinBoxT"));
        spinBoxT->setMaximumSize(QSize(53, 20));
        spinBoxT->setMaximum(254);
        spinBoxT->setValue(10);

        gridLayout->addWidget(spinBoxT, 0, 1, 1, 1);

        spinBoxFinalT = new QSpinBox(widget);
        spinBoxFinalT->setObjectName(QStringLiteral("spinBoxFinalT"));
        spinBoxFinalT->setMaximumSize(QSize(53, 20));

        gridLayout->addWidget(spinBoxFinalT, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gboxWindow = new QGroupBox(widget);
        gboxWindow->setObjectName(QStringLiteral("gboxWindow"));
        gboxWindow->setMinimumSize(QSize(256, 81));
        gboxWindow->setMaximumSize(QSize(256, 16777215));
        gboxWindow->setAutoFillBackground(true);
        radN1 = new QRadioButton(gboxWindow);
        radN1->setObjectName(QStringLiteral("radN1"));
        radN1->setGeometry(QRect(10, 20, 82, 17));
        radN1->setChecked(false);
        radN3 = new QRadioButton(gboxWindow);
        radN3->setObjectName(QStringLiteral("radN3"));
        radN3->setGeometry(QRect(10, 60, 82, 17));
        radN2 = new QRadioButton(gboxWindow);
        radN2->setObjectName(QStringLiteral("radN2"));
        radN2->setGeometry(QRect(10, 40, 82, 17));
        radN2->setChecked(true);

        verticalLayout->addWidget(gboxWindow);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addWidget(widget);

        viewTabs = new QTabWidget(centralWidget);
        viewTabs->setObjectName(QStringLiteral("viewTabs"));

        horizontalLayout_3->addWidget(viewTabs);

        SusanForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SusanForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 903, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SusanForm->setMenuBar(menuBar);
        statusBar = new QStatusBar(SusanForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SusanForm->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(SusanForm);
        QObject::connect(sliderT, SIGNAL(valueChanged(int)), spinBoxT, SLOT(setValue(int)));
        QObject::connect(spinBoxT, SIGNAL(valueChanged(int)), sliderT, SLOT(setValue(int)));
        QObject::connect(sliderW, SIGNAL(valueChanged(int)), spinBoxFinalT, SLOT(setValue(int)));
        QObject::connect(spinBoxFinalT, SIGNAL(valueChanged(int)), sliderW, SLOT(setValue(int)));

        viewTabs->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SusanForm);
    } // setupUi

    void retranslateUi(QMainWindow *SusanForm)
    {
        SusanForm->setWindowTitle(QApplication::translate("SusanForm", "SUSAN-2D Corner Detector", 0));
        actionExit->setText(QApplication::translate("SusanForm", "Exit", 0));
        addButton->setText(QApplication::translate("SusanForm", "Add", 0));
        removeButton->setText(QApplication::translate("SusanForm", "Remove", 0));
        label->setText(QApplication::translate("SusanForm", "T", 0));
        label_2->setText(QApplication::translate("SusanForm", "t", 0));
        gboxWindow->setTitle(QApplication::translate("SusanForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("SusanForm", "0.5", 0));
        radN3->setText(QApplication::translate("SusanForm", "0.9", 0));
        radN2->setText(QApplication::translate("SusanForm", "0.7", 0));
        menuFile->setTitle(QApplication::translate("SusanForm", "File", 0));
        menuHelp->setTitle(QApplication::translate("SusanForm", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SusanForm: public Ui_SusanForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSAN_FORM_H
