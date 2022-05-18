#include "mainwidget.h"

MainWidget::MainWidget(QWidget* parent) : QWidget(parent) {
	drawingPanel = new DrawingPanel(this);
	colorButton = new QPushButton("Change color", this);
	colorDialog = new QColorDialog(this);
	timerButton = new QPushButton("Start", this);
	connect(timerButton, SIGNAL(clicked()), SLOT(onClickedTimerButton()));
	connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addWidget(drawingPanel);
	mainLayout->addWidget(colorButton);
	mainLayout->addWidget(timerButton);
	setLayout(mainLayout);
}
MainWidget::~MainWidget() {}
void MainWidget::onClickedColorButton() {
	drawingPanel->setColor(QColorDialog::getColor());
	drawingPanel->update();
}
void MainWidget::onClickedTimerButton() {
	drawingPanel->changeTimerStatus();
	if (timerButton->text() == "Start")
		timerButton->setText("Stop");
	else 
		timerButton->setText("Start");
}