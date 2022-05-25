#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <istream>
#include <list>
#include <fstream>

class Student {
public:
    Student(const std::string& studentName, int studentCourse);
    Student() = default;
    std::string getStudentName() const;
    int getStudentCourse() const;
    std::string getInfo() const;
private:
    std::string studentName;
    int studentCourse;
};

std::istream& operator>>(std::istream& in, Student& student);
void readFromFile(std::list<Student>& studentsList, const std::string& fileName);

#endif 