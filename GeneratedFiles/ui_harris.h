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
#include <QtWidgets/QProgressBar>
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
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *fileListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider;
    QLabel *label;
    QSpinBox *spinBox;
    QDoubleSpinBox *spinBoxK;
    QLabel *label_k;
    QLabel *label_Global;
    QGroupBox *gboxWindow;
    QRadioButton *radN1;
    QRadioButton *radN2;
    QRadioButton *radN3;
    QRadioButton *radN4;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxBeforeSmooth;
    QLabel *labelCorners;
    QLabel *labelNCorners;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveButton;
    QProgressBar *progressBar;
    QTabWidget *viewTabs;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HarrisForm)
    {
        if (HarrisForm->objectName().isEmpty())
            HarrisForm->setObjectName(QStringLiteral("HarrisForm"));
        HarrisForm->resize(877, 569);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        HarrisForm->setWindowIcon(icon);
        actionExit = new QAction(HarrisForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(HarrisForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(281, 16777215));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
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
        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximumSize(QSize(50, 20));
        spinBox->setMinimum(1);
        spinBox->setMaximum(255);
        spinBox->setValue(200);

        gridLayout->addWidget(spinBox, 1, 1, 1, 1);

        spinBoxK = new QDoubleSpinBox(widget);
        spinBoxK->setObjectName(QStringLiteral("spinBoxK"));
        spinBoxK->setMinimum(0.01);
        spinBoxK->setMaximum(0.8);
        spinBoxK->setSingleStep(0.01);
        spinBoxK->setValue(0.04);

        gridLayout->addWidget(spinBoxK, 0, 1, 1, 1);

        label_k = new QLabel(widget);
        label_k->setObjectName(QStringLiteral("label_k"));

        gridLayout->addWidget(label_k, 0, 2, 1, 1);

        label_Global = new QLabel(widget);
        label_Global->setObjectName(QStringLiteral("label_Global"));

        gridLayout->addWidget(label_Global, 1, 2, 1, 1);


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
        radN2 = new QRadioButton(gboxWindow);
        radN2->setObjectName(QStringLiteral("radN2"));
        radN2->setGeometry(QRect(10, 40, 82, 17));
        radN2->setChecked(true);
        radN3 = new QRadioButton(gboxWindow);
        radN3->setObjectName(QStringLiteral("radN3"));
        radN3->setGeometry(QRect(10, 60, 82, 17));
        radN4 = new QRadioButton(gboxWindow);
        radN4->setObjectName(QStringLiteral("radN4"));
        radN4->setGeometry(QRect(10, 80, 82, 17));

        verticalLayout->addWidget(gboxWindow);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxBeforeSmooth = new QCheckBox(widget);
        checkBoxBeforeSmooth->setObjectName(QStringLiteral("checkBoxBeforeSmooth"));
        checkBoxBeforeSmooth->setGeometry(QRect(11, 383, 88, 17));

        horizontalLayout_2->addWidget(checkBoxBeforeSmooth);

        labelCorners = new QLabel(widget);
        labelCorners->setObjectName(QStringLiteral("labelCorners"));

        horizontalLayout_2->addWidget(labelCorners);

        labelNCorners = new QLabel(widget);
        labelNCorners->setObjectName(QStringLiteral("labelNCorners"));

        horizontalLayout_2->addWidget(labelNCorners);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMaximumSize(QSize(108, 23));

        horizontalLayout_3->addWidget(saveButton);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);
        progressBar->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        progressBar->setTextVisible(true);

        horizontalLayout_3->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(widget);

        viewTabs = new QTabWidget(centralWidget);
        viewTabs->setObjectName(QStringLiteral("viewTabs"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(viewTabs->sizePolicy().hasHeightForWidth());
        viewTabs->setSizePolicy(sizePolicy);
        viewTabs->setMinimumSize(QSize(680, 500));

        horizontalLayout_4->addWidget(viewTabs);

        HarrisForm->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HarrisForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HarrisForm->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, fileListWidget);

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
        label->setText(QApplication::translate("HarrisForm", "Thresholds", 0));
        label_k->setText(QApplication::translate("HarrisForm", "k", 0));
        label_Global->setText(QApplication::translate("HarrisForm", "Global", 0));
        gboxWindow->setTitle(QApplication::translate("HarrisForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("HarrisForm", "2x2", 0));
        radN2->setText(QApplication::translate("HarrisForm", "3x3", 0));
        radN3->setText(QApplication::translate("HarrisForm", "4x4", 0));
        radN4->setText(QApplication::translate("HarrisForm", "5 x 5", 0));
        checkBoxBeforeSmooth->setText(QApplication::translate("HarrisForm", "Smoothing", 0));
        labelCorners->setText(QApplication::translate("HarrisForm", "Corners detected: ", 0));
        labelNCorners->setText(QApplication::translate("HarrisForm", "0", 0));
        saveButton->setText(QApplication::translate("HarrisForm", "Save corners", 0));
    } // retranslateUi

};

namespace Ui {
    class HarrisForm: public Ui_HarrisForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HARRIS_H
