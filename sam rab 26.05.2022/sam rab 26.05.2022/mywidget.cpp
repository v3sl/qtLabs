#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent) : QWidget{ parent } {
	drawingPanel = new DrawingPanel(this);
	createMenuBar();
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->setMenuBar(menuBar);
	layout->addWidget(drawingPanel);
	setLayout(layout);
}
void MyWidget::openChosenFile() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "", tr("Images (*.png *.xpm *.jpg)"));
	QImage imageFromFile;
	imageFromFile.load(fileName);
	int imageWidth = width();
	int imageHeight = height();
	imageFromFile = imageFromFile.scaled(imageWidth, imageHeight);
	drawingPanel->setImage(QPixmap::fromImage(imageFromFile));
}
void MyWidget::saveInformationAsFile() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), "untitled.png", tr("Images(*.png * .xpm * .jpg"));
	int nameEndPosition = fileName.lastIndexOf('.');
	++nameEndPosition;
	int nameLength = fileName.length() - nameEndPosition;
	QString format = fileName.right(nameLength);
	int imageWidth = width();
	int imageHeight = height();
	QPixmap imageForSave = QPixmap::grabWidget(this, 0, 0, imageWidth, imageHeight);
	imageForSave.save(fileName, format.toUpper().toUtf8());
}
void MyWidget::newPainting() {
	drawingPanel->clear();
	update();
}
void MyWidget::changeStep() {
	bool ok;
	QString newStep = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr(""), QLineEdit::Normal,
		"", &ok);
	if (ok && !newStep.isEmpty())
		drawingPanel->setPaintStep(newStep.toInt());
}
void MyWidget::changeColor() {
	QColor newColor = QColorDialog::getColor();
	drawingPanel->setPenColor(newColor);
}
void MyWidget::changePenWidth() {
	bool ok;
	QString newWidth = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr(""), QLineEdit::Normal,
		"", &ok);
	if (ok && !newWidth.isEmpty())
		drawingPanel->setPenWidth(newWidth.toInt());
}
void MyWidget::changeStartPoint() {
	bool ok;
	QString newCoordinates = QInputDialog::getText(this, tr("QInputDialog::getText()"),
		tr(""), QLineEdit::Normal,
		"", &ok);
	if (ok && !newCoordinates.isEmpty()) {
		QString newX;
		QString newY;
		for (int i = 0; newCoordinates[i] != ' '; ++i)
			newX.push_back(newCoordinates[i]);
		for (int i = newX.size(); newCoordinates[i] != '\0'; ++i)
			newY.push_back(newCoordinates[i]);
		QPoint newStartPoint(newX.toInt(), newY.toInt());
		drawingPanel->setStartPoint(newStartPoint);
		drawingPanel->addNewPoint(QPoint(-1, -1));
		drawingPanel->addNewPoint(drawingPanel->getStartPoint());
		drawingPanel->setEndPoint(newStartPoint);
	}
}
void MyWidget::keyPressEvent(QKeyEvent* event) {
	switch (event->key()) {
	case Qt::Key_Up:
		moveForward();
		break;
	case Qt::Key_Down:
		moveBackward();
		break;
	case Qt::Key_Right:
		moveRight();
		break;
	case Qt::Key_Left:
		moveLeft();
		break;
	case Qt::Key_O:
		openChosenFile();
		break;
	case Qt::Key_A:
		saveInformationAsFile();
		break;
	case Qt::Key_N:
		newPainting();
		break;
	case Qt::Key_S:
		changeStep();
		break;
	case Qt::Key_C:
		changeColor();
		break;
	case Qt::Key_W:
		changePenWidth();
		break;
	case Qt::Key_K:
		changeStartPoint();
		break;
	}
}
void MyWidget::createMenuBar() {
	createFileMenu();
	createEditMenu();
	menuBar = new QMenuBar(this);
	menuBar->addMenu(fileMenu);
	menuBar->addMenu(editMenu);
}
void MyWidget::createFileMenu() {
	createFileActions();
	fileMenu = new QMenu("file", this);
	fileMenu->addSeparator();
	fileMenu->addAction(openFileAction);
	fileMenu->addAction(saveFileAction);
	fileMenu->addAction(newPaintingAction);
}
void MyWidget::createFileActions() {
	createOpenFileAction();
	createSaveFileAction();
	createNewPaintingAction();
}
void MyWidget::createOpenFileAction() {
	openFileAction = new QAction("open", this);
	openFileAction->setShortcut(Qt::Key_O);
	openFileAction->setStatusTip(tr("open file"));
	connect(openFileAction, &QAction::triggered, this, &MyWidget::openChosenFile);
}
void MyWidget::createSaveFileAction() {
	saveFileAction = new QAction("&save as", this);
	saveFileAction->setShortcut(Qt::Key_A);
	saveFileAction->setStatusTip(tr("save file as"));
	connect(saveFileAction, &QAction::triggered, this, &MyWidget::saveInformationAsFile);
}
void MyWidget::createNewPaintingAction() {
	newPaintingAction = new QAction("&new", this);
	newPaintingAction->setShortcut(Qt::Key_N);
	newPaintingAction->setStatusTip(tr("create new painting"));
	connect(newPaintingAction, &QAction::triggered, this, &MyWidget::newPainting);
}
void MyWidget::createEditMenu() {
	createEditActions();
	editMenu = new QMenu("&edit", this);
	editMenu->addAction(changeStepAction);
	editMenu->addAction(changeColorAction);
	editMenu->addAction(changePenWidthAction);
	editMenu->addAction(changeStartPointAction);
}
void MyWidget::createEditActions() {
	createChangeStepAction();
	createChangeColorAction();
	createChangePenWidthAction();
	createChangeStartPointAction();
}
void MyWidget::createChangeStepAction() {
	changeStepAction = new QAction("&step", this);
	changeStepAction->setShortcut(Qt::Key_S);
	changeStepAction->setStatusTip(tr("change line step"));
	connect(changeStepAction, &QAction::triggered, this, &MyWidget::changeStep);
}
void MyWidget::createChangeColorAction() {
	changeColorAction = new QAction("&color", this);
	changeColorAction->setShortcut(Qt::Key_C);
	changeColorAction->setStatusTip(tr("change color"));
	connect(changeColorAction, &QAction::triggered, this, &MyWidget::changeColor);
}
void MyWidget::createChangePenWidthAction() {
	changePenWidthAction = new QAction("&width", this);
	changePenWidthAction->setShortcut(Qt::Key_W);
	changePenWidthAction->setStatusTip(tr("change width"));
	connect(changePenWidthAction, &QAction::triggered, this, &MyWidget::changePenWidth);
}
void MyWidget::createChangeStartPointAction() {
	changeStartPointAction = new QAction("&start point", this);
	changeStartPointAction->setShortcut(Qt::Key_K);
	changeStartPointAction->setStatusTip(tr("change start point"));
	connect(changeStartPointAction, &QAction::triggered, this, &MyWidget::changeStartPoint);
}
bool MyWidget::isInWidget(const QPointF& point) const {
	if (point.x() >= 0 && point.x() <= width() &&
		point.y() >= 0 && point.y() <= height())
		return true;
	return false;
}
void MyWidget::moveForward() {
	QPointF newEndPoint = QPointF(drawingPanel->getEndPoint().rx(), drawingPanel->getEndPoint().ry() - drawingPanel->getPaintStep());
	if (isInWidget(newEndPoint)) {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(newEndPoint);
	}
	else {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(QPoint(-1, -1));
	}
	update();
}
void MyWidget::moveBackward() {
	QPointF newEndPoint = QPointF(drawingPanel->getEndPoint().rx(), drawingPanel->getEndPoint().ry() + drawingPanel->getPaintStep());
	if (isInWidget(newEndPoint)) {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(newEndPoint);
	}
	else {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(QPoint(-1, -1));
	}
	update();
}
void MyWidget::moveRight() {
	QPointF newEndPoint = QPointF(drawingPanel->getEndPoint().rx() + drawingPanel->getPaintStep(), drawingPanel->getEndPoint().ry());
	if (isInWidget(newEndPoint)) {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(newEndPoint);
	}
	else {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(QPoint(-1, -1));
	}
	update();
}
void MyWidget::moveLeft() {
	QPointF newEndPoint = QPointF(drawingPanel->getEndPoint().rx() - drawingPanel->getPaintStep(), drawingPanel->getEndPoint().ry());
	if (isInWidget(newEndPoint)) {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(newEndPoint);
	}
	else {
		drawingPanel->setEndPoint(newEndPoint);
		drawingPanel->addNewPoint(QPoint(-1, -1));
	}
	update();
}