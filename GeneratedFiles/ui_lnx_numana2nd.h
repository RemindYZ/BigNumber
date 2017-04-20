/********************************************************************************
** Form generated from reading UI file 'lnx_numana2nd.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LNX_NUMANA2ND_H
#define UI_LNX_NUMANA2ND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lnx_NumAna2ndClass
{
public:
    QWidget *centralWidget;
    QLineEdit *Input;
    QRadioButton *Taylor;
    QRadioButton *NumIntegration;
    QRadioButton *RationalApproximation;
    QPushButton *Caculate;
    QTextBrowser *textBrowser;
    QLabel *label;
    QSpinBox *lenth;
    QLabel *label_2;
    QPushButton *clear;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *buttonGroup;

    void setupUi(QMainWindow *Lnx_NumAna2ndClass)
    {
        if (Lnx_NumAna2ndClass->objectName().isEmpty())
            Lnx_NumAna2ndClass->setObjectName(QStringLiteral("Lnx_NumAna2ndClass"));
        Lnx_NumAna2ndClass->resize(291, 479);
        Lnx_NumAna2ndClass->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(Lnx_NumAna2ndClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Input = new QLineEdit(centralWidget);
        Input->setObjectName(QStringLiteral("Input"));
        Input->setGeometry(QRect(20, 20, 81, 21));
        Input->setMaxLength(6);
        Taylor = new QRadioButton(centralWidget);
        buttonGroup = new QButtonGroup(Lnx_NumAna2ndClass);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(Taylor);
        Taylor->setObjectName(QStringLiteral("Taylor"));
        Taylor->setGeometry(QRect(20, 90, 89, 16));
        NumIntegration = new QRadioButton(centralWidget);
        buttonGroup->addButton(NumIntegration);
        NumIntegration->setObjectName(QStringLiteral("NumIntegration"));
        NumIntegration->setGeometry(QRect(20, 120, 131, 16));
        RationalApproximation = new QRadioButton(centralWidget);
        buttonGroup->addButton(RationalApproximation);
        RationalApproximation->setObjectName(QStringLiteral("RationalApproximation"));
        RationalApproximation->setGeometry(QRect(20, 150, 141, 16));
        Caculate = new QPushButton(centralWidget);
        Caculate->setObjectName(QStringLiteral("Caculate"));
        Caculate->setGeometry(QRect(170, 90, 101, 51));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 190, 271, 211));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 20, 81, 21));
        lenth = new QSpinBox(centralWidget);
        lenth->setObjectName(QStringLiteral("lenth"));
        lenth->setGeometry(QRect(20, 50, 81, 22));
        lenth->setMinimum(1);
        lenth->setMaximum(25);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 50, 91, 21));
        clear = new QPushButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(170, 150, 101, 23));
        Lnx_NumAna2ndClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Lnx_NumAna2ndClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 291, 23));
        Lnx_NumAna2ndClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lnx_NumAna2ndClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Lnx_NumAna2ndClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Lnx_NumAna2ndClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Lnx_NumAna2ndClass->setStatusBar(statusBar);

        retranslateUi(Lnx_NumAna2ndClass);
        QObject::connect(Caculate, SIGNAL(clicked()), Lnx_NumAna2ndClass, SLOT(Caculate()));
        QObject::connect(clear, SIGNAL(clicked()), Lnx_NumAna2ndClass, SLOT(Clear()));

        QMetaObject::connectSlotsByName(Lnx_NumAna2ndClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lnx_NumAna2ndClass)
    {
        Lnx_NumAna2ndClass->setWindowTitle(QApplication::translate("Lnx_NumAna2ndClass", "Lnx\350\256\241\347\256\227\345\231\250", 0));
        Taylor->setText(QApplication::translate("Lnx_NumAna2ndClass", "\346\263\260\345\213\222\345\261\225\345\274\200", 0));
        NumIntegration->setText(QApplication::translate("Lnx_NumAna2ndClass", "\346\225\260\345\200\274\347\247\257\345\210\206\357\274\210\351\276\231\350\264\235\346\240\274\357\274\211", 0));
        RationalApproximation->setText(QApplication::translate("Lnx_NumAna2ndClass", "\346\234\211\347\220\206\351\200\274\350\277\221", 0));
        Caculate->setText(QApplication::translate("Lnx_NumAna2ndClass", "Caculate", 0));
        label->setText(QApplication::translate("Lnx_NumAna2ndClass", "\350\276\223\345\205\245x:[1,100]", 0));
        label_2->setText(QApplication::translate("Lnx_NumAna2ndClass", "\347\262\276\345\272\246\357\274\210\345\260\217\346\225\260\344\275\215\346\225\260\357\274\211", 0));
        clear->setText(QApplication::translate("Lnx_NumAna2ndClass", "clear", 0));
    } // retranslateUi

};

namespace Ui {
    class Lnx_NumAna2ndClass: public Ui_Lnx_NumAna2ndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LNX_NUMANA2ND_H
