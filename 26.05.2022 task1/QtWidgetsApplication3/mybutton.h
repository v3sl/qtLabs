#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton {
public:
	MyButton();
	int getValue() const { return value; }
	void setValue(int v) { value = v; }
protected:
	void paintEvent(QPaintEvent*);
private:
	int value;
};

#endif