#ifndef TASK3WIDGET_hH
#define TASK3WIDGET_hH

#include <QPushButton>
#include <QLineEdit>
#include <QMouseEvent>
#include <QLabel>
#include <QVBoxLayout>
#include "drawfunction.h"

class task3Widget :public QWidget {
	Q_OBJECT
public:
	task3Widget(QWidget* parent = nullptr);
	~task3Widget();
protected:
	void mousePressEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
protected slots:
	void onChangedEditX();
private:
	DrawFunction* drawFunction;
	QLineEdit* editX;
	QLineEdit* editY;
	QLabel* yLabel;
};

#endif 