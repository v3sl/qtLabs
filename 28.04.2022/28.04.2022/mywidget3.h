#pragma once 

#include <QtWidgets/QWidget>
#include "qpainter.h"

class MyWidget3 : public QWidget {
	Q_OBJECT
public:
	MyWidget3(QWidget* parent = nullptr);
	~MyWidget3() {}
protected:
	void paintEvent(QPaintEvent* event);
private:
	std::vector<std::vector<int>> data;
};