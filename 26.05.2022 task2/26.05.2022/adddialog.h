#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include "student.h"

class Student;
class AddDialog : public QDialog {
public:
	AddDialog(QWidget* parent = nullptr);
	Student student() const;

private:
	QLineEdit* nameLineEdit;
	QLineEdit* yearLineEdit;
};

#endif 