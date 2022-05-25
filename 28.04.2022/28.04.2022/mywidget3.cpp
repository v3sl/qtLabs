#include "mywidget3.h"

MyWidget3::MyWidget3(QWidget* parent) : QWidget(parent) {
	int size = rand() % 10 + 1;
	for (int i = 0; i < size; ++i) {
		std::vector<int> temp;
		for (int j = 0; j < size; ++j) {
			temp.push_back(rand() % 3 - 1);
		}
		data.push_back(temp);
	}
}

void MyWidget3::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QRect widgetRect = this->rect();
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 5));
	int dx = widgetRect.width() / data.size();
	int dy = widgetRect.height() / data.size();
	const double scale = static_cast<double>(dy) / 15 + static_cast<double>(dx) / 7.5;
	painter.setFont(QFont("arial", scale));
	for (int i = 1; i < data.size(); ++i) {
		painter.drawLine(dx * i, 0, dx * i, widgetRect.height());
		painter.drawLine(0, dy * i, widgetRect.width(), dy * i);
	}
	int index = 0;
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data.size(); ++j) {
			QString str;
			switch (data[i][j]) {
			case -1:
				break;
			case 0:
				painter.drawEllipse(i * dx + scale, j * dy + scale, 3 * scale, 3 * scale);
				break;
			case 1:
				painter.drawLine(i * dx + scale, j * dy + scale, (i + 1) * dx - scale, (j + 1) * dy - scale);
				painter.drawLine((i + 1) * dx - scale, j * dy + scale, i * dx + scale, (j + 1) * dy - scale);
				break;
			default:
				break;
			}
		}
	}
}