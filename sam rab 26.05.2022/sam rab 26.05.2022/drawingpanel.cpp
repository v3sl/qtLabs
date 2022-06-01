#include "drawingpanel.h"

DrawingPanel::DrawingPanel(QWidget* parent) : QWidget{ parent } {
	startPoint = new QPointF(100, 100);
	endPoint = new QPointF(100, 100);
	points.push_back(*startPoint);
	paintStep = 50;
	penWidth = 3;
	color = new QColor(Qt::green);
	currentPen = new QPen(*color, penWidth);
	backgroundImage = new QPixmap();
}
QPointF DrawingPanel::getStartPoint() { return *startPoint; }
QPointF DrawingPanel::getEndPoint() { return *endPoint; }
int DrawingPanel::getPaintStep() { return paintStep; }
void DrawingPanel::setStartPoint(const QPointF& point) {
	delete startPoint;
	startPoint = new QPointF(point);
}
void DrawingPanel::setEndPoint(const QPointF& point) {
	delete endPoint;
	endPoint = new QPointF(point);
}
void DrawingPanel::addNewPoint(const QPointF& point) { 
	points.push_back(point); 
	pens.push_back(*currentPen);
}
void DrawingPanel::setPaintStep(int step) { paintStep = step; }
void DrawingPanel::setPenWidth(int width) { currentPen->setWidth(width); }
void DrawingPanel::setPenColor(const QColor& color) { currentPen->setColor(color); }
void DrawingPanel::clear() {
	points.clear();
	delete startPoint;
	startPoint = new QPointF(100, 100);
	points.push_back(*startPoint);
	endPoint = new QPointF(100, 100);
	paintStep = 50;
	penWidth = 3;
	color = new QColor(Qt::green);
}
void DrawingPanel::setImage(const QPixmap& image) {
	delete backgroundImage;
	backgroundImage = new QPixmap(image);
}
void DrawingPanel::paintEvent(QPaintEvent*) {
	QPainter painter(this);
	int imageWidth = width();
	int imageHeight = height();
	painter.drawPixmap(0, 0, imageWidth, imageHeight, *backgroundImage);
	painter.setPen(QPen(Qt::red, 3));
	delete startPoint;
	startPoint = new QPointF(points[points.size() - 1]);
	painter.drawEllipse(*startPoint, currentPen->width(), currentPen->width()); //draw point pointer
	painter.setPen(*currentPen);
	for (int i = 1; i < points.size(); ++i) {
		if ((points[i - 1].x() == -1 && points[i - 1].y() == -1) ||
			(points[i].rx() == -1 && points[i].ry() == -1))
			continue;
		else {
			painter.setPen(pens[i - 1]);
			painter.drawLine(points[i - 1], points[i]);
		}
	}
}