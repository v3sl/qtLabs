#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mybutton.h"

class Widget : public QWidget {
	Q_OBJECT
public:
	Widget(QWidget* parent = nullptr);
	~Widget();
private slots:
	void onClickedButton();
private:
	static const int size = 3;
	MyButton* buttons[size * size];
	bool isWin();
	bool isLose();
	bool isDraw();
};
#endif 