#include <QPainter>
#include "mybutton.h"

MyButton::MyButton() : value(-1) {}
void MyButton::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	QPen crossPen(Qt::green, 3);
	QPen zeroPen(Qt::red, 3);
	if (value == 0) {
		painter.setPen(zeroPen);
		painter.drawEllipse(0, 0, width(), height());
	}
	else if (value == 1) {
		painter.setPen(crossPen);
		painter.drawLine(0, 0, width(), height());
		painter.drawLine(width(), 0, 0, height());
	}
	else
		painter.eraseRect(0,0,width(),height());
}