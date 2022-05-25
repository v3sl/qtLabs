#include <QtWidgets/QApplication>
#include "mainwidget.h"

int main(int argc, char* argv[]) {
	QApplication application(argc, argv);
	MainWidget task3Window;
	task3Window.show();
	return application.exec();
}