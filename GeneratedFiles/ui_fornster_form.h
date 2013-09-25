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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
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
    QDoubleSpinBox *spinBoxW;
    QDoubleSpinBox *spinBoxQ;
    QSlider *sliderW;
    QSlider *sliderQ;
    QLabel *label;
    QLabel *label_2;
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
        gboxWindow = new QGroupBox(centralWidget);
        gboxWindow->setObjectName(QStringLiteral("gboxWindow"));
        gboxWindow->setGeometry(QRect(10, 410, 171, 81));
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
        spinBoxW = new QDoubleSpinBox(centralWidget);
        spinBoxW->setObjectName(QStringLiteral("spinBoxW"));
        spinBoxW->setGeometry(QRect(150, 360, 62, 22));
        spinBoxW->setMinimum(0.05);
        spinBoxW->setMaximum(1.5);
        spinBoxW->setSingleStep(0.01);
        spinBoxW->setValue(0.73);
        spinBoxQ = new QDoubleSpinBox(centralWidget);
        spinBoxQ->setObjectName(QStringLiteral("spinBoxQ"));
        spinBoxQ->setGeometry(QRect(150, 320, 62, 22));
        spinBoxQ->setMinimum(0.5);
        spinBoxQ->setMaximum(0.75);
        spinBoxQ->setSingleStep(0.01);
        spinBoxQ->setValue(0.54);
        sliderW = new QSlider(centralWidget);
        sliderW->setObjectName(QStringLiteral("sliderW"));
        sliderW->setGeometry(QRect(10, 360, 131, 22));
        sliderW->setMinimum(50);
        sliderW->setMaximum(150);
        sliderW->setValue(73);
        sliderW->setOrientation(Qt::Horizontal);
        sliderQ = new QSlider(centralWidget);
        sliderQ->setObjectName(QStringLiteral("sliderQ"));
        sliderQ->setGeometry(QRect(10, 320, 131, 22));
        sliderQ->setMinimum(50);
        sliderQ->setMaximum(75);
        sliderQ->setValue(54);
        sliderQ->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(220, 360, 16, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 320, 16, 20));
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
        gboxWindow->setTitle(QApplication::translate("FornsterForm", "Non-maxima suppression window", 0));
        radN1->setText(QApplication::translate("FornsterForm", "0.5", 0));
        radN3->setText(QApplication::translate("FornsterForm", "0.9", 0));
        radN2->setText(QApplication::translate("FornsterForm", "0.7", 0));
        label->setText(QApplication::translate("FornsterForm", "w", 0));
        label_2->setText(QApplication::translate("FornsterForm", "q", 0));
    } // retranslateUi

};

namespace Ui {
    class FornsterForm: public Ui_FornsterForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORNSTER_FORM_H
