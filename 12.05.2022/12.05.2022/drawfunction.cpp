#include "drawfunction.h"

DrawFunction::DrawFunction(QWidget* parent) : QWidget(parent) {}
void DrawFunction::paintEvent(QPaintEvent*) {
	const double newCenterX = (width() - 2 * padding) / 2.0;
	const double newCenterY = (height() - 2 * padding) / 2.0;
	QPointF originOfCoordinates(newCenterX, newCenterY);
	QPainter painter(this);
	painter.translate(originOfCoordinates);
	painter.setPen(QPen(Qt::black, 1));
	QPointF xAxisBegin(0, -newCenterY);
	QPointF xAxisEnd(0, newCenterY);
	QPointF yAxixBegin(-newCenterX, 0);
	QPointF yAxixEnd(newCenterX, 0);
	painter.drawLine(xAxisBegin,xAxisEnd);
	painter.drawLine(yAxixBegin,yAxixEnd);
	const double dx = (width() - 2 * padding) / (static_cast<double>(abs(segmentBegin)) + abs(segmentEnd));
	const double dy = (height() - 2 * padding) / (static_cast<double>(abs(segmentBegin)) + abs(segmentEnd));
	for (int i = segmentBegin; i <= segmentEnd; ++i) {
		QPointF dividingLineBegin(i * dx, 10);
		QPointF dividingLineEnd(i * dx, -10);
		painter.drawLine(dividingLineBegin,dividingLineEnd);
		QPointF textPoint(i * dx + 5, -15);
		painter.drawText(textPoint, QString::number(i));
	}
	for (double i = segmentBegin; i < segmentEnd; i += 0.001) {
		QPointF coord;
		coord.rx() = i * dx;
		coord.ry() = -(i * i + sin(i)) * dy;
		painter.drawPoint(coord);
	}
}