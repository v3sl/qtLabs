/********************************************************************************
** Form generated from reading UI file 'prtictactoe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRTICTACTOE_H
#define UI_PRTICTACTOE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prTicTacToeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *prTicTacToeClass)
    {
        if (prTicTacToeClass->objectName().isEmpty())
            prTicTacToeClass->setObjectName(QString::fromUtf8("prTicTacToeClass"));
        prTicTacToeClass->resize(600, 400);
        menuBar = new QMenuBar(prTicTacToeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        prTicTacToeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(prTicTacToeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        prTicTacToeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(prTicTacToeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        prTicTacToeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(prTicTacToeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        prTicTacToeClass->setStatusBar(statusBar);

        retranslateUi(prTicTacToeClass);

        QMetaObject::connectSlotsByName(prTicTacToeClass);
    } // setupUi

    void retranslateUi(QMainWindow *prTicTacToeClass)
    {
        prTicTacToeClass->setWindowTitle(QCoreApplication::translate("prTicTacToeClass", "prTicTacToe", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prTicTacToeClass: public Ui_prTicTacToeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRTICTACTOE_H
