#include <iostream>
#include <string>
using namespace std;

struct Student {
	string name;
	float math;
	float literature;
	float avg;
};

void setStudent(Student&);
void printStudent(Student);
void setStudent_avg(Student&);

int main() {
	Student student;
	setStudent(student);
	setStudent_avg(student);
	printStudent(student);
	return 0;
}

void setStudent(Student& student) {
	cout << "Name: ";
	getline(cin,student.name);
	cout << "Math score: ";
	cin >> student.math;
	cout << "Literature score: ";
	cin >> student.literature;
}
void printStudent(Student student) {
	cout << "Name: " + student.name +"\n";
	cout << "Math score: "<<student.math<<endl;
	cout << "Literature score: "<<student.literature<<endl;
	cout << "Average score: " << student.avg<<endl;
}
void setStudent_avg(Student& student) {
	student.avg = (student.math + student.literature) / 2;
}