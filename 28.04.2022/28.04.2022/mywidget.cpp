#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget(parent) {
	std::ifstream inputFile("input.txt");
	std::string inputStr;
	while (inputFile >> inputStr)
		data.push_back(std::stoi(inputStr));
}

void MyWidget::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QRect widgetRect = this->rect();
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2.5));
	painter.setBrush(QBrush(Qt::gray));
	int max = *(std::max_element(data.begin(), data.end()));
	int dx = widgetRect.width() / data.size();
	int dy = widgetRect.height() / max;
	for (int i = 0; i < data.size(); ++i) {
		painter.drawRect(i * dx, widgetRect.height() - data[i] * dy, dx, widgetRect.height());
		painter.drawText(i * dx + dx / 2, 0.99 * widgetRect.height(), QString::number(data[i]));
	}
}