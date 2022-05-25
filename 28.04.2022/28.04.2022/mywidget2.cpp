#include "mywidget2.h"

MyWidget2::MyWidget2(QWidget* parent) : QWidget(parent) {
	std::ifstream inputFile("input2.txt");
	std::string inputStr;
	while (inputFile >> inputStr)
		data.push_back(std::stoi(inputStr));
}

void MyWidget2::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QRect widgetRect = this->rect();
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2.5));
	painter.setBrush(QBrush(Qt::gray));
	int max = *(std::max_element(data.begin(), data.end()));
	int min = *(std::min_element(data.begin(), data.end()));
	max = std::max(abs(max), std::abs(min));
	int dx = widgetRect.width() / data.size();
	int dy = widgetRect.height() / max;
	for (int i = 0; i < data.size(); ++i) {
		painter.drawRect(i * dx, (widgetRect.height() - data[i] * dy) / 2, dx, 0.5 * data[i] * dy);
		painter.drawText(i * dx + dx / 2, (widgetRect.height() - data[i] * dy / 2) / 2, QString::number(data[i]));
	}
}