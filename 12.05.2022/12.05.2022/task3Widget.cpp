#include "task3Widget.h"

task3Widget::task3Widget(QWidget* parent) :QWidget(parent) {
	drawFunction = new DrawFunction(this);
	editX = new QLineEdit(this);
	QLabel* lblX = new QLabel("x", this);
	lblX->setFixedSize(15, 15);
	editY = new QLineEdit(this);
	editY->setDisabled(true);
	QLabel* lblY = new QLabel("y", this);
	lblY->setFixedSize(15, 15);
	yLabel = new QLabel(this);
	connect(editX, SIGNAL(textChanged(const QString&)), SLOT(onChangedEditX()));
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(drawFunction);
	mainLayout->addWidget(lblX);
	mainLayout->addWidget(editX);
	mainLayout->addWidget(lblY);
	mainLayout->addWidget(editY);
	setLayout(mainLayout);
}
task3Widget::~task3Widget() {}
void task3Widget::mousePressEvent(QMouseEvent* event) {
	QPointF coord = event->pos();
	const double pointX = coord.rx() - (width() - 2 * padding) / 2.0;
	const double dx = (width() - 2 * padding) / 6.0;
	const QString pointY(QString::number((pointX / dx) * (pointX / dx) + sin((pointX / dx))));
	yLabel->setText(pointY);
	QRect yLabelRect(coord.rx(), coord.ry(), 100, 100);
	yLabel->setGeometry(yLabelRect);
	yLabel->show();
}
void task3Widget::mouseMoveEvent(QMouseEvent* event) {
	QPointF coord = event->pos();
	const double pointX = coord.rx() - (width() - 2 * padding) / 2.0;
	const double dx = (width() - 2 * padding) / 6.0;
	const QString pointY(QString::number((pointX / dx) * (pointX / dx) + sin((pointX / dx))));
	yLabel->setText(pointY);
	QRect yLabelRect(coord.rx(), coord.ry(), 100, 100);
	yLabel->setGeometry(yLabelRect);
	yLabel->show();
}
void task3Widget::mouseReleaseEvent(QMouseEvent* event) { yLabel->hide(); }
void task3Widget::onChangedEditX() {
	const double pointX = editX->text().toDouble();
	editY->setText(QString::number(pointX * pointX + sin(pointX)));
}