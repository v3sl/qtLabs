#include <QGridLayout>
#include <QMessageBox>
#include "widget.h"
#include "mybutton.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
	QGridLayout* layout = new QGridLayout();
	for (int i = 0; i < size * size; ++i) {
		buttons[i] = new MyButton();
		layout->addWidget(buttons[i], i / size, i % size);
		connect(buttons[i], SIGNAL(clicked()), SLOT(onClickedButton()));
	}
	this->setLayout(layout);
}
Widget::~Widget() {}
void Widget::onClickedButton() {
	MyButton* source = (MyButton*)QObject::sender();
	if (source->getValue() == 1)
		return;
	if (source->getValue() == -1)
		source->setValue(1);
	if (isWin()) {
		for (int i = 0; i < 9; ++i)
			buttons[i]->setValue(-1);
		update();
		QMessageBox winMesasge;
		winMesasge.setText("you won");
		winMesasge.exec();
	}
	for (int i = 0; i < 9; ++i) {
		if (buttons[i]->getValue() == -1) {
			buttons[i]->setValue(0);
			break;
		}
	}
	if (isLose()) {
		for (int i = 0; i < 9; ++i)
			buttons[i]->setValue(-1);
		update();
		QMessageBox lostMesasge;
		lostMesasge.setText("you lost");
		lostMesasge.exec();
	}
	if (isDraw()) {
		for (int i = 0; i < 9; ++i)
			buttons[i]->setValue(-1);
		update();
		QMessageBox lostMesasge;
		lostMesasge.setText("draw");
		lostMesasge.exec();
	}
	update();
}
bool Widget::isWin() {
	if ((buttons[0]->getValue() == 1 && buttons[1]->getValue() == 1 && buttons[2]->getValue() == 1) ||
		(buttons[3]->getValue() == 1 && buttons[4]->getValue() == 1 && buttons[5]->getValue() == 1) ||
		(buttons[6]->getValue() == 1 && buttons[7]->getValue() == 1 && buttons[8]->getValue() == 1) ||
		(buttons[0]->getValue() == 1 && buttons[3]->getValue() == 1 && buttons[6]->getValue() == 1) ||
		(buttons[1]->getValue() == 1 && buttons[4]->getValue() == 1 && buttons[7]->getValue() == 1) ||
		(buttons[2]->getValue() == 1 && buttons[5]->getValue() == 1 && buttons[8]->getValue() == 1) ||
		(buttons[0]->getValue() == 1 && buttons[4]->getValue() == 1 && buttons[8]->getValue() == 1) ||
		(buttons[2]->getValue() == 1 && buttons[4]->getValue() == 1 && buttons[6]->getValue() == 1))
		return true;
	return false;
}
bool Widget::isLose() {
	if ((buttons[0]->getValue() == 0 && buttons[1]->getValue() == 0 && buttons[2]->getValue() == 0) ||
		(buttons[3]->getValue() == 0 && buttons[4]->getValue() == 0 && buttons[5]->getValue() == 0) ||
		(buttons[6]->getValue() == 0 && buttons[7]->getValue() == 0 && buttons[8]->getValue() == 0) ||
		(buttons[0]->getValue() == 0 && buttons[3]->getValue() == 0 && buttons[6]->getValue() == 0) ||
		(buttons[1]->getValue() == 0 && buttons[4]->getValue() == 0 && buttons[7]->getValue() == 0) ||
		(buttons[2]->getValue() == 0 && buttons[5]->getValue() == 0 && buttons[8]->getValue() == 0) ||
		(buttons[0]->getValue() == 0 && buttons[4]->getValue() == 0 && buttons[8]->getValue() == 0) ||
		(buttons[2]->getValue() == 0 && buttons[4]->getValue() == 0 && buttons[6]->getValue() == 0))
		return true;
	return false;
}
bool Widget::isDraw() {
	for (int i = 0; i < 9; ++i) {
		if (buttons[i]->getValue() == -1)
			return false;
	}
	return true;
}
