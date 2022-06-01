#include <QApplication>
#include "mainwindow.h"

int main(int argc, char* argv[]) {
	QApplication application(argc, argv);
	MainWindow window;
	window.resize(600, 700);
	window.show();
	return application.exec();
}