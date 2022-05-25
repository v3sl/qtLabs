#include "widget.h"

Widget::Widget(QWidget* parent) : QWidget(parent) {
	studentsListWidget = new QListWidget(this);
	loadButton = new QPushButton("load from file", this);
	addButton = new QPushButton("add new student", this);
	deleteButton = new QPushButton("delete student", this);
	courseLabel = new QLabel("course", this);
	courseEdit = new QLineEdit(this);
	connect(studentsListWidget, SIGNAL(itemSelectionChanged()), SLOT(onStudentChanged()));
	connect(loadButton, SIGNAL(clicked()), SLOT(onLoadClicked()));
	connect(addButton, SIGNAL(clicked()), SLOT(onAddClicked()));
	connect(deleteButton, SIGNAL(clicked()), SLOT(onDeleteClicked()));
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(studentsListWidget);
	layout->addWidget(loadButton);
	layout->addWidget(addButton);
	layout->addWidget(deleteButton);
	layout->addWidget(courseLabel);
	layout->addWidget(courseEdit);
	setLayout(layout);
}
Widget::~Widget() {}
void Widget::onLoadClicked() {
	QString fileName = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
	readFromFile(students, fileName.toStdString());
	showStudents();
}
void Widget::onAddClicked() {
	AddDialog* addDialog = new AddDialog(this);
	if (addDialog->exec() == QDialog::Accepted) {
		Student tempStudentObject = addDialog->student();
		students.push_back(tempStudentObject);
		showStudents();
	}
}
void Widget::showStudents() {
	studentsListWidget->clear();
	for (const Student& student : students) {
		QString qStr(student.getInfo().c_str());
		studentsListWidget->addItem(qStr);
	}
}
void Widget::onDeleteClicked() {
	int stuentNumber = studentsListWidget->currentRow();
	if (stuentNumber == -1)
		return;
	QMessageBox messageBox;
	messageBox.setText(QString::number(stuentNumber));
	messageBox.exec();
	studentsListWidget->takeItem(stuentNumber);
	std::list<Student>::iterator iterator = students.begin();
	for (int i = 0; i < stuentNumber; ++i)
		++iterator;
	students.erase(iterator);
}
void Widget::onStudentChanged() {
	int stuentNumber = studentsListWidget->currentRow();
	std::list<Student>::iterator iterator = students.begin();
	for (int i = 0; i < stuentNumber; i++)
		++iterator;
	courseEdit->setText(QString::number(iterator->getStudentCourse()));
}