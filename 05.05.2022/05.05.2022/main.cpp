#include <QtWidgets/QApplication>
#include "bstwidget.h"
#include "bstwidget2.h"

int main(int argc, char* argv[]) {
	QApplication a(argc, argv);
	/*bstwidget w;
	w.show();*/
	bstwidget2 w2;
	w2.show();
	return a.exec();
}

