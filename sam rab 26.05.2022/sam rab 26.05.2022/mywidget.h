#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QMenuBar>
#include <QInputDialog>
#include <QColorDialog>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QKeyEvent>
#include "drawingpanel.h"

class MyWidget : public QWidget {
	Q_OBJECT
public:
	explicit MyWidget(QWidget* parent = nullptr);
protected slots:
	void openChosenFile();
	void saveInformationAsFile();
	void newPainting();
	void changeStep();
	void changeColor();
	void changePenWidth();
	void changeStartPoint();
protected:
	void keyPressEvent(QKeyEvent*) override;
private:
	QMenuBar* menuBar;
	QMenu* fileMenu;
	QAction* openFileAction;
	QAction* saveFileAction;
	QAction* newPaintingAction;
	QMenu* editMenu;
	QAction* changeStepAction;
	QAction* changeColorAction;
	QAction* changePenWidthAction;
	QAction* changeStartPointAction;
	DrawingPanel* drawingPanel;
	void createMenuBar();
	void createFileMenu();
	void createFileActions();
	void createOpenFileAction();
	void createSaveFileAction();
	void createNewPaintingAction();
	void createEditMenu();
	void createEditActions();
	void createChangeStepAction();
	void createChangeColorAction();
	void createChangePenWidthAction();
	void createChangeStartPointAction();
	bool isInWidget(const QPointF& point) const;
	void moveForward();
	void moveBackward();
	void moveRight();
	void moveLeft();
};

#endif 