#include <QtWidgets/QApplication>
#include "mywidget.h"
#include "mywidget2.h"
#include "mywidget3.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	QApplication app(argc, argv);
	MyWidget w;
	w.show();
	MyWidget2 w2;
	w2.show();
	MyWidget3 w3;
	w3.show();
	return app.exec();
}