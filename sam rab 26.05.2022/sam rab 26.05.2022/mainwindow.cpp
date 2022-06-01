#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	myWidget = new MyWidget(this);
	myWidget->setFocus();
	this->setCentralWidget(myWidget);
}
MainWindow::~MainWindow() {}