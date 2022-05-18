/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainwidgetClass)
    {
        if (mainwidgetClass->objectName().isEmpty())
            mainwidgetClass->setObjectName(QString::fromUtf8("mainwidgetClass"));
        mainwidgetClass->resize(600, 400);
        menuBar = new QMenuBar(mainwidgetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        mainwidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainwidgetClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainwidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(mainwidgetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mainwidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mainwidgetClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mainwidgetClass->setStatusBar(statusBar);

        retranslateUi(mainwidgetClass);

        QMetaObject::connectSlotsByName(mainwidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainwidgetClass)
    {
        mainwidgetClass->setWindowTitle(QCoreApplication::translate("mainwidgetClass", "mainwidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwidgetClass: public Ui_mainwidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
