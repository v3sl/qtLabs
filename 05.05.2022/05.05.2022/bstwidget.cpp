#include "bstwidget.h"

bstwidget::bstwidget(QWidget* parent) : QMainWindow(parent) {
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
	tree.insert(8);
	tree.insert(11);
	tree.insert(50);
	tree.insert(48);
	tree.insert(124);
	tree.insert(122);
	tree.insert(41);
	tree.insert(31);
	tree.insert(33);
	tree.insert(26);
	tree.insert(24);
}
void paintPart(node* currentNode, double dx, double dy, double scale, QPainter& painter) {
	if (currentNode == nullptr)
		return;
	else {
		painter.drawEllipse(dx - 0.5 * scale, dy, scale, scale);
		int currentNodeData = currentNode->data;
		int n = 0;
		if (currentNodeData < 0) {
			++n;
			currentNodeData = abs(currentNodeData);
		}
		n += (currentNodeData == 0 ? 1 : int(log10(currentNodeData) + 1));
		QFont font("Times", 0.25 * scale);
		painter.setFont(font);
		painter.drawText(dx - 0.125 * n * scale, dy + 0.625 * scale, QString::number(currentNode->data));
	}
	if (currentNode->left != nullptr) {
		painter.drawLine(dx - 0.5 * scale, dy + 0.5 * scale, dx - 1.75 * scale, dy + 2 * scale);
		paintPart(currentNode->left, dx - 1.75 * scale, dy + 2 * scale, 0.5*scale, painter);
	}
	if (currentNode->right != nullptr) {
		painter.drawLine(dx + 0.5 * scale, dy + 0.5 * scale, dx + 1.75 * scale, dy + 2 * scale);
		paintPart(currentNode->right, dx + 1.75 * scale , dy + 2 * scale, 0.5* scale, painter);
	}
}
void bstwidget::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QRect widgetRect = this->rect();
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2.5));
	painter.setBrush(QBrush(Qt::gray));
	double dx = widgetRect.width() / 2.0;
	double dy = 0;
	double scale = 0.25 * dx;
	paintPart(tree.getRoot(), dx, dy, scale, painter);
}