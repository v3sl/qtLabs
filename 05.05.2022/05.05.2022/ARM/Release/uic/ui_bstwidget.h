/********************************************************************************
** Form generated from reading UI file 'bstwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSTWIDGET_H
#define UI_BSTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bstwidgetClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *bstwidgetClass)
    {
        if (bstwidgetClass->objectName().isEmpty())
            bstwidgetClass->setObjectName(QString::fromUtf8("bstwidgetClass"));
        bstwidgetClass->resize(600, 400);
        menuBar = new QMenuBar(bstwidgetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        bstwidgetClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(bstwidgetClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        bstwidgetClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(bstwidgetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        bstwidgetClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(bstwidgetClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        bstwidgetClass->setStatusBar(statusBar);

        retranslateUi(bstwidgetClass);

        QMetaObject::connectSlotsByName(bstwidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *bstwidgetClass)
    {
        bstwidgetClass->setWindowTitle(QCoreApplication::translate("bstwidgetClass", "bstwidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bstwidgetClass: public Ui_bstwidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSTWIDGET_H
