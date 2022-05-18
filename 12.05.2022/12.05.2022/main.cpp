#include <QtWidgets/QApplication>
#include "mainwidget.h"
#include "widget.h"
#include "task3Widget.h"

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	MainWidget w;
	w.resize(800, 700);
	w.setWindowTitle("Function Graph");
	w.show();
	Widget w2;
	w2.show();
	w2.resize(1000, 600);
	w2.setWindowTitle("hello!!!");
	task3Widget w3;
	w3.show();
	w3.resize(500, 500);
	return a.exec();
}
