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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
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

class Ui_HarrisForm
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
    QGroupBox *gboxWindow;
    QRadioButton *radN1;
    QRadioButton *radN3;
    QRadioButton *radN2;
    QRadioButton *radN4;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QLabel *label;
    QSpinBox *spinBox;
    QDoubleSpinBox *spinBoxK;
    QLabel *label_k;
    QLabel *label_Global;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBoxAfterSmooth;
    QCheckBox *checkBoxBeforeSmooth;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HarrisForm)
    {
        if (HarrisForm->objectName().isEmpty())
            HarrisForm->setObjectName(QStringLiteral("HarrisForm"));
        HarrisForm->resize(877, 569);
        actionExit = new QAction(HarrisForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HarrisForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 182, 25));
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
        fileListWidget->setGeometry(QRect(10, 10, 211, 231));
        fileListWidget->setDragEnabled(false);
        fileListWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fileListWidget->setTextElideMode(Qt::ElideRight);
        gboxWindow = new QGroupBox(centralWidget);
        gboxWindow->setObjectName(QStringLiteral("gboxWindow"));
        gboxWindow->setGeometry(QRect(10, 410, 171, 101));
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
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 290, 211, 69));
        gridLayout = new QGridLayout(layoutWidget2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(layoutWidget2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximumSize(QSize(50, 20));
        spinBox->setMinimum(1);
        spinBox->setMaximum(255);
        spinBox->setValue(200);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        spinBoxK = new QDoubleSpinBox(layoutWidget2);
        spinBoxK->setObjectName(QStringLiteral("spinBoxK"));
        spinBoxK->setMinimum(0.01);
        spinBoxK->setMaximum(0.8);
        spinBoxK->setSingleStep(0.01);
        spinBoxK->setValue(0.04);

        gridLayout->addWidget(spinBoxK, 0, 1, 1, 1);

        label_k = new QLabel(layoutWidget2);
        label_k->setObjectName(QStringLiteral("label_k"));

        gridLayout->addWidget(label_k, 0, 2, 1, 1);

        label_Global = new QLabel(layoutWidget2);
        label_Global->setObjectName(QStringLiteral("label_Global"));

        gridLayout->addWidget(label_Global, 1, 2, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 360, 211, 41));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        checkBoxAfterSmooth = new QCheckBox(widget);
        checkBoxAfterSmooth->setObjectName(QStringLiteral("checkBoxAfterSmooth"));

        gridLayout_2->addWidget(checkBoxAfterSmooth, 1, 3, 1, 1);

        checkBoxBeforeSmooth = new QCheckBox(widget);
        checkBoxBeforeSmooth->setObjectName(QStringLiteral("checkBoxBeforeSmooth"));

        gridLayout_2->addWidget(checkBoxBeforeSmooth, 1, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        HarrisForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HarrisForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 877, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        HarrisForm->setMenuBar(menuBar);
        statusBar = new QStatusBar(HarrisForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HarrisForm->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, removeButton);
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
        addButton->setText(QApplication::translate("HarrisForm", "Add", 0));
        removeButton->setText(QApplication::translate("HarrisForm", "Remove", 0));
        gboxWindow->setTitle(QApplication::translate("HarrisForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("HarrisForm", "2 x 2", 0));
        radN3->setText(QApplication::translate("HarrisForm", "4 x 4", 0));
        radN2->setText(QApplication::translate("HarrisForm", "3 x 3", 0));
        radN4->setText(QApplication::translate("HarrisForm", "5 x 5", 0));
        label->setText(QApplication::translate("HarrisForm", "Thresholds", 0));
        label_k->setText(QApplication::translate("HarrisForm", "k", 0));
        label_Global->setText(QApplication::translate("HarrisForm", "Global", 0));
        checkBoxAfterSmooth->setText(QApplication::translate("HarrisForm", "Postprocessed", 0));
        checkBoxBeforeSmooth->setText(QApplication::translate("HarrisForm", "Preprocessed", 0));
        label_2->setText(QApplication::translate("HarrisForm", "Smoothing", 0));
        menuFile->setTitle(QApplication::translate("HarrisForm", "File", 0));
        menuHelp->setTitle(QApplication::translate("HarrisForm", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class HarrisForm: public Ui_HarrisForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARRIS_H
