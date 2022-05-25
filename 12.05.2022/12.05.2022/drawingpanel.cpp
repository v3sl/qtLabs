#include "drawingpanel.h"

DrawingPanel::DrawingPanel(QWidget* parent) : QWidget{ parent } {
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
	currentI = CURRENT_I_START;
}
void DrawingPanel::changeTimerStatus() {
	if (timer->isActive() == 0)
		timer->start(20);
	else
		timer->stop();
}
void DrawingPanel::setColor(const QColor& color) { this->color = color; }
void DrawingPanel::paintEvent(QPaintEvent*) {
	const int scaleRatio = 28000;
	const double padding = static_cast<double>(width()) * height() / scaleRatio;
	const double newCenterX = (width() - 2 * padding) / 2;
	const double newCenterY = (height() - 2 * padding) / 2;
	QPointF originOfCoordinates(newCenterX, newCenterY);
	QPainter painter(this);
	painter.translate(originOfCoordinates);
	const double diameter = static_cast<double>(width()) * height() / scaleRatio / 2;
	const double penWdith = static_cast<double>(width()) * height() * 3 / 20 / scaleRatio;
	for (int i = -newCenterX; i < newCenterX; ++i) {
		QPointF coord;
		coord.rx() = i;
		coord.ry() = -i * i * 0.01;
		if (i == currentI) {
			painter.setPen(QPen(Qt::red, penWdith));
			int ellipseStartX = coord.rx() - 0.5 * diameter;
			int ellipseSrartY = coord.ry() - 0.5 * diameter;
			painter.drawEllipse(ellipseStartX, ellipseSrartY, diameter, diameter);
		}
		else {
			painter.setPen(QPen(color, penWdith));
			painter.drawPoint(QPointF(coord.rx(), coord.ry()));
		}
	}
}
void DrawingPanel::slotTimerAlarm() {
	if (currentI == CURRENT_I_FINISH)
		currentI = CURRENT_I_START;
	++currentI;
	update();
}