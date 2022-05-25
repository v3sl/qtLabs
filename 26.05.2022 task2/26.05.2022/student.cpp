#include "student.h"

Student::Student(const std::string& studentName, int course) : studentName(studentName), studentCourse(course) {}
std::string Student::getStudentName() const { return studentName; }
int Student::getStudentCourse() const { return studentCourse; }
std::string Student::getInfo() const { return studentName + " - " + std::to_string(studentCourse); }
std::istream& operator>>(std::istream& in, Student& student) {
	std::string studenName;
	int studentCourse;
	in >> studenName >> studentCourse;
	student = Student(studenName, studentCourse);
	return in;
}
void readFromFile(std::list<Student>& studentsList, const std::string& fileName) {
	std::ifstream fin(fileName);
	Student tempStudentObject;

	while (fin >> tempStudentObject)
		studentsList.push_back(tempStudentObject);
}