#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QColorDialog>
#include <QVBoxLayout>
#include "drawingpanel.h"

class MainWidget : public QWidget {
	Q_OBJECT
public:
	MainWidget(QWidget* parent = nullptr);
	~MainWidget();
protected slots:
	void onClickedColorButton();
	void onClickedTimerButton();
private:
	DrawingPanel* drawingPanel;
	QPushButton* colorButton;
	QColorDialog* colorDialog;
	QPushButton* timerButton;
};

#endif