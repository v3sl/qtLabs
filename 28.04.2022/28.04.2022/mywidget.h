#pragma once

#include <QtWidgets/QWidget>
#include <fstream>
#include "qpainter.h"

class MyWidget : public QWidget {
	Q_OBJECT
public:
	MyWidget(QWidget* parent = nullptr);
	~MyWidget() {}
protected:
	void paintEvent(QPaintEvent* event);
private:
	std::vector<int> data;
};