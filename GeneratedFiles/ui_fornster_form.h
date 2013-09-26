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
    QHBoxLayout *horizontalLayout_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *fileListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QGridLayout *gridLayout;
    QSlider *sliderQ;
    QDoubleSpinBox *spinBoxQ;
    QLabel *label_2;
    QSlider *sliderW;
    QDoubleSpinBox *spinBoxW;
    QLabel *label;
    QGroupBox *gboxWindow;
    QRadioButton *radN1;
    QRadioButton *radN3;
    QRadioButton *radN2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxSmoothing;
    QLabel *labelCorners;
    QLabel *labelNCorners;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *saveButton;
    QProgressBar *progressBar;
    QTabWidget *viewTabs;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FornsterForm)
    {
        if (FornsterForm->objectName().isEmpty())
            FornsterForm->setObjectName(QStringLiteral("FornsterForm"));
        FornsterForm->resize(978, 545);
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        FornsterForm->setWindowIcon(icon);
        actionExit = new QAction(FornsterForm);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(FornsterForm);
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
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(6);
        sliderQ = new QSlider(widget);
        sliderQ->setObjectName(QStringLiteral("sliderQ"));
        sliderQ->setMinimum(50);
        sliderQ->setMaximum(100);
        sliderQ->setValue(54);
        sliderQ->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderQ, 0, 0, 1, 1);

        spinBoxQ = new QDoubleSpinBox(widget);
        spinBoxQ->setObjectName(QStringLiteral("spinBoxQ"));
        spinBoxQ->setMinimum(0.5);
        spinBoxQ->setMaximum(1);
        spinBoxQ->setSingleStep(0.01);
        spinBoxQ->setValue(0.54);

        gridLayout->addWidget(spinBoxQ, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        sliderW = new QSlider(widget);
        sliderW->setObjectName(QStringLiteral("sliderW"));
        sliderW->setMinimum(50);
        sliderW->setMaximum(1000);
        sliderW->setValue(73);
        sliderW->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(sliderW, 1, 0, 1, 1);

        spinBoxW = new QDoubleSpinBox(widget);
        spinBoxW->setObjectName(QStringLiteral("spinBoxW"));
        spinBoxW->setMinimum(0.05);
        spinBoxW->setMaximum(10);
        spinBoxW->setSingleStep(0.01);
        spinBoxW->setValue(0.73);

        gridLayout->addWidget(spinBoxW, 1, 1, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 2, 1, 1);


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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBoxSmoothing = new QCheckBox(widget);
        checkBoxSmoothing->setObjectName(QStringLiteral("checkBoxSmoothing"));

        horizontalLayout_2->addWidget(checkBoxSmoothing);

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

        FornsterForm->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FornsterForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FornsterForm->setStatusBar(statusBar);
        QWidget::setTabOrder(addButton, removeButton);
        QWidget::setTabOrder(removeButton, fileListWidget);

        retranslateUi(FornsterForm);

        viewTabs->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(FornsterForm);
    } // setupUi

    void retranslateUi(QMainWindow *FornsterForm)
    {
        FornsterForm->setWindowTitle(QApplication::translate("FornsterForm", "Fornster Corner Detector", 0));
        actionExit->setText(QApplication::translate("FornsterForm", "Exit", 0));
        addButton->setText(QApplication::translate("FornsterForm", "Add", 0));
        removeButton->setText(QApplication::translate("FornsterForm", "Remove", 0));
        label_2->setText(QApplication::translate("FornsterForm", "q", 0));
        label->setText(QApplication::translate("FornsterForm", "w", 0));
        gboxWindow->setTitle(QApplication::translate("FornsterForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("FornsterForm", "3x3", 0));
        radN3->setText(QApplication::translate("FornsterForm", "5x5", 0));
        radN2->setText(QApplication::translate("FornsterForm", "4x4", 0));
        checkBoxSmoothing->setText(QApplication::translate("FornsterForm", "Use smoothing", 0));
        labelCorners->setText(QApplication::translate("FornsterForm", "Corners detected: ", 0));
        labelNCorners->setText(QApplication::translate("FornsterForm", "0", 0));
        saveButton->setText(QApplication::translate("FornsterForm", "Save corners", 0));
    } // retranslateUi

};

namespace Ui {
    class FornsterForm: public Ui_FornsterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORNSTER_FORM_H
