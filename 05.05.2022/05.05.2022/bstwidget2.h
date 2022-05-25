#pragma once

#include <QtWidgets/QMainWindow>
#include "qpainter.h"
#include "bst2.h"

class bstwidget2 : public QMainWindow
{
    Q_OBJECT

public:
    bstwidget2(QWidget* parent = Q_NULLPTR);
    ~bstwidget2() = default;

protected:
    void paintEvent(QPaintEvent* event);
private:
    BST2 tree;
};
