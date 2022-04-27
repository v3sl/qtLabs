#pragma once

#include <QtWidgets/QWidget>
#include <fstream>
#include "qpainter.h"

class MyWidget2 : public QWidget {
	Q_OBJECT
public:
	MyWidget2(QWidget* parent = nullptr);
	~MyWidget2() {}
protected:
	void paintEvent(QPaintEvent* event);
private:
	std::vector<int> data;
};