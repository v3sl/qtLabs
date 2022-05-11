#include "bstwidget2.h"

bstwidget2::bstwidget2(QWidget* parent) : QMainWindow(parent) {
	tree.insert(30);
	tree.insert(20);
	tree.insert(25);
	tree.insert(7);
	tree.insert(45);
	tree.insert(38);
	tree.insert(51);
	tree.insert(5);
	tree.insert(10);
	tree.insert(123);
	tree.insert(-1);
	tree.insert(32);
	tree.insert(42);
	tree.insert(43);
	tree.insert(49);
	tree.insert(6);
}
void paintPart(BST2& tree,int currentIndex, double dx, double dy, double scale, QPainter& painter) {
	if (tree.getLeafByIndex(currentIndex).isFilled() == 1) {
		painter.drawEllipse(dx - 0.5 * scale, dy, scale, scale);
		int currentNodeData = tree.getLeafByIndex(currentIndex).getData();
		int n = 0;
		if (currentNodeData < 0) {
			++n;
			currentNodeData = abs(currentNodeData);
		}
		n += (currentNodeData == 0 ? 1 : int(log10(currentNodeData) + 1));
		QFont font("Times", 0.25 * scale);
		painter.setFont(font);
		painter.drawText(dx - 0.125 * n * scale, dy + 0.625 * scale, QString::number(currentNodeData));
	}
	if (tree.getLeafByIndex(2 * currentIndex + 1).isFilled() == 1) {
		painter.drawLine(dx - 0.5 * scale, dy + 0.5 * scale, dx - 1.75 * scale, dy + 2 * scale);
		paintPart(tree, 2 * currentIndex + 1, dx - 1.75 * scale, dy + 2 * scale, 0.5 * scale, painter);
	}
	if (tree.getLeafByIndex(2 * currentIndex + 2).isFilled() == 1) {
		painter.drawLine(dx + 0.5 * scale, dy + 0.5 * scale, dx + 1.75 * scale, dy + 2 * scale);
		paintPart(tree, 2 * currentIndex + 2, dx + 1.75 * scale, dy + 2 * scale, 0.5 * scale, painter);
	}
}
void bstwidget2::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QRect widgetRect = this->rect();
	QPainter painter(this);
	painter.setPen(QPen(Qt::green, 2.5));
	painter.setBrush(QBrush(Qt::gray));
	double dx = widgetRect.width() / 2.0;
	double dy = 0;
	double scale = 0.25 * dx;
	paintPart(tree,0, dx, dy, scale, painter);
}