#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
	fileOpenButton = new QPushButton("open file", this);
	fileSaveButton = new QPushButton("save file", this);
	sliderLabel = new QLabel("Width", this);
	penWidthSlider = new QSlider(Qt::Horizontal, this);
	penWidthSlider->setMinimum(1);
	penWidthSlider->setMaximum(20);
	penWidthSlider->setTickInterval(1);
	penWidthSlider->setTickPosition(QSlider::TicksAbove);
	colorButton = new QPushButton("Color", this);
	colorDialog = new QColorDialog(this);
	painterPen.setColor(Qt::black);
	painterPen.setWidth(1);
	connect(fileOpenButton, SIGNAL(clicked()), SLOT(onClickedFileOpenButton()));
	connect(fileSaveButton, SIGNAL(clicked()), SLOT(onClickedFileSaveButton()));
	connect(penWidthSlider, SIGNAL(valueChanged(int)), SLOT(onMoveSlider()));
	connect(colorButton, SIGNAL(clicked()), SLOT(onClickedColorButton()));
	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->setAlignment(Qt::AlignBottom);
	mainLayout->addWidget(fileOpenButton);
	mainLayout->addWidget(fileSaveButton);
	mainLayout->addWidget(sliderLabel);
	mainLayout->addWidget(penWidthSlider);
	mainLayout->addWidget(colorButton);
	mainLayout->addWidget(colorDialog);
	setLayout(mainLayout);
}
Widget::~Widget() {}
void Widget::paintEvent(QPaintEvent* event) {
	fileOpenButton->setFixedHeight(0.05 * height());
	fileSaveButton->setFixedHeight(0.05 * height());
	sliderLabel->setFixedHeight(0.05 * height());
	penWidthSlider->setFixedHeight(0.05 * height());
	colorButton->setFixedHeight(0.05 * height());
	QPainter painter(this);
	painter.setPen(painterPen);
	int imageWidth = width();
	int imageHeight = 0.65 * height();
	painter.drawTiledPixmap(START_X_COORDINATE, START_Y_COORDINATE, imageWidth, imageHeight, backgroundImage);
	if (lines.empty() && currentLine.empty())
		return;
	for (auto& line : lines) {
		for (int i = 0; i < line.size() - 1; i++)
			painter.drawLine(line[i], line[static_cast<std::vector<QPoint, std::allocator<QPoint>>::size_type>(i) + 1]);
	}
	for (int i = 1; i < currentLine.size(); i++)
		painter.drawLine(currentLine[static_cast<std::vector<QPoint, std::allocator<QPoint>>::size_type>(i) - 1], currentLine[i]);
}
void Widget::mouseMoveEvent(QMouseEvent* event) {
	if ((event->buttons() & Qt::LeftButton)) {
		QPoint point = event->pos();
		currentLine.push_back(point);
		update();
	}
}
void Widget::mouseReleaseEvent(QMouseEvent* event) {
	if (event->button() == Qt::LeftButton) {
		lines.push_back(currentLine);
		currentLine.clear();
	}
}
void Widget::onClickedColorButton() {
	painterPen.setColor(QColorDialog::getColor());
	update();
}
void Widget::onMoveSlider() {
	painterPen.setWidth(penWidthSlider->value());
	update();
}
void Widget::onClickedFileOpenButton() {
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"),"", tr("Images (*.png *.xpm *.jpg)"));
	QImage imageFromFile;
	imageFromFile.load(fileName);
	backgroundImage = QPixmap::fromImage(imageFromFile);
	int imageWidth = width();
	int imageHeight = 0.65 * height();
	backgroundImage = backgroundImage.scaled(imageWidth, imageHeight);
}
void Widget::onClickedFileSaveButton() {
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save as"), "untitled.png",tr("Images(*.png * .xpm * .jpg"));
	int nameEndPosition = fileName.lastIndexOf('.');
	++nameEndPosition;
	int nameLength = fileName.length() - nameEndPosition;
	QString format = fileName.right(nameLength);
	int imageWidth = width();
	int imageHeight = 0.65 * height();
	QPixmap imageForSave = QPixmap::grabWidget(this, START_X_COORDINATE, START_Y_COORDINATE, imageWidth, imageHeight);
	imageForSave.save(fileName, format.toUpper().toUtf8());
}