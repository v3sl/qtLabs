#ifndef DRAWINGPANEL_H
#define DRAWINGPANEL_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QColor>

constexpr int CURRENT_I_START = -210;
constexpr int CURRENT_I_FINISH = 210;

class DrawingPanel : public QWidget {
	Q_OBJECT
public:
	explicit DrawingPanel(QWidget* parent = nullptr);
	void changeTimerStatus();
	void setColor(const QColor& color);
protected:
	void paintEvent(QPaintEvent*);
protected slots:
	void slotTimerAlarm();
private:
	QTimer* timer;
	QColor color;
	int currentI;
};

#endif 