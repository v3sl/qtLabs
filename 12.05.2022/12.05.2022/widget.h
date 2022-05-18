#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QSlider>
#include <QColorDialog>
#include <QVBoxLayout>

constexpr int START_X_COORDINATE = 0;
constexpr int START_Y_COORDINATE = 0;

class Widget : public QWidget {
	Q_OBJECT
public:
	Widget(QWidget* parent = nullptr);
	~Widget();
protected:
	void paintEvent(QPaintEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
protected slots:
	void onClickedFileOpenButton();
	void onClickedFileSaveButton();
	void onMoveSlider();
	void onClickedColorButton();
private:
	QVector<QPoint> currentLine;
	QVector<QVector<QPoint>> lines;
	QPushButton* fileOpenButton;
	QPushButton* fileSaveButton;
	QLabel* sliderLabel;
	QSlider* penWidthSlider;
	QPushButton* colorButton;
	QColorDialog* colorDialog;
	QPen painterPen;
	QPixmap backgroundImage;
};

#endif 