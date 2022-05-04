#pragma once

#include <QtWidgets/QMainWindow>
#include "qpainter.h"
#include "bst1.h"

class bstwidget : public QMainWindow
{
    Q_OBJECT

public:
    bstwidget(QWidget *parent = Q_NULLPTR);
    ~bstwidget() {};

protected:
    void paintEvent(QPaintEvent* event);
private:
    BST1 tree;
};
