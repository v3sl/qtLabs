#ifndef DRAWFUNCTION_H
#define DRAWFUNCTION_H

#include <QWidget>
#include <QPainter>
#include "qmath.h"

constexpr int segmentBegin = -3;
constexpr int segmentEnd = 3;
constexpr int padding = 20;

class DrawFunction :public QWidget{
	Q_OBJECT
public:
	explicit DrawFunction(QWidget* parent = nullptr);
protected:
	void paintEvent(QPaintEvent*);
};

#endif 