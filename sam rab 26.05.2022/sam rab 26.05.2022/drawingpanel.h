#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QPixmap>

class DrawingPanel : public QWidget {
	Q_OBJECT
public:
	explicit DrawingPanel(QWidget* parent = nullptr);
	QPointF getStartPoint();
	QPointF getEndPoint();
	int getPaintStep();
	void setStartPoint(const QPointF& point);
	void setEndPoint(const QPointF& point);
	void addNewPoint(const QPointF& point);
	void setPaintStep(int step);
	void setPenWidth(int width);
	void setPenColor(const QColor& color);
	void clear();
	void setImage(const QPixmap& image);
protected:
	void paintEvent(QPaintEvent*);
private:
	QPointF* startPoint;
	QPointF* endPoint;
	QVector	<QPointF> points;
	QVector <QPen> pens;
	int paintStep;
	int penWidth;
	QColor* color;
	QPen* currentPen;
	QPixmap* backgroundImage;
};

#endif 