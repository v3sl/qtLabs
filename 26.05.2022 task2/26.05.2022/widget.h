#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include "adddialog.h"
#include "student.h"

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
private slots:
    void onLoadClicked();
    void onAddClicked();
    void onDeleteClicked();
    void onStudentChanged();
private:
    std::list<Student> students;
    QListWidget* studentsListWidget;
    QPushButton* loadButton;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QLabel* courseLabel;
    QLineEdit* courseEdit;
    void showStudents();
};

#endif 