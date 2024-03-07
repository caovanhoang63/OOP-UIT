#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct Date {
	int day;
	int month;
	int year;
};
struct Candidate {
	int id;
	string name;
	Date date_of_birth;
	float math;
	float literature;
	float english;
};
struct TestCandidate {
	int number_of_candidate;
	Candidate* list_of_candidate;
};
// read date
istream& operator>>(istream& is, Date& date) {
	cout << "Day: ";
	is >> date.day;
	cout << "Month: ";
	is >> date.month;
	cout << "Year: ";
	is >> date.year;
	return is;
}
// print date
ostream& operator<<(ostream& os, Date date) {
	string s = to_string(date.day) + "-" +  to_string(date.month) + "-" + to_string(date.year);
	os << s;
	return os;
}
// read candidate
istream& operator>>(istream& is, Candidate& candidate) {
	cout << "Id:";
	is >> candidate.id;
	is.ignore();
	cout << "Name: ";
	getline(is,candidate.name);
	cout << "Date of birth: "<<endl;
	is >> candidate.date_of_birth;
	cout << "Math score: ";
	is >> candidate.math;
	cout << "Literature score: ";
	is >> candidate.literature;
	cout << "English score: ";
	is >> candidate.english;
	return is;
}
// print candidate
ostream& operator<<(ostream& os, Candidate candidate) {
	os << "Id: "<<candidate.id;
	os << "Name: "<< candidate.name;
	os << "Date of birth: "<<candidate.date_of_birth;
	os << "Math score: "<<candidate.math;
	os << "Literature score: "<<candidate.literature;
	os << "English score: " << candidate.english;
	return os;
}
// read testcandidate
istream& operator>>(istream& is, TestCandidate& list) {
	cout << "Number of candidate: ";
	is >> list.number_of_candidate;
	list.list_of_candidate = new Candidate[list.number_of_candidate];
	for (int i = 0; i < list.number_of_candidate; i++) {
		cout << i + 1<< "th candidate: " << endl;
		cin >> *(list.list_of_candidate + i);
	}
	return is;
}
// print testcandidate table
ostream& operator<<(ostream& os, TestCandidate list) {
	cout << "List of candidate: "<<endl;
		cout << "+-----------------------------------------------------------------------------------------+\n";
		cout << "| Srl |    ID    |       Name        | Date of birth |    Math    | Literature |  English |\n";
		cout << "+-----------------------------------------------------------------------------------------+\n";
	for (int i = 0; i < list.number_of_candidate; i++) {
		cout << "|"
			<< setw(3) << i + 1 << "  |"
			<< setw(9) << (list.list_of_candidate+i)->id << " |"
			<< setw(16) << (list.list_of_candidate + i)->name << "   " << "|"
			<< setw(15) << (list.list_of_candidate + i)->date_of_birth << "" << "|"
			<< setw(8) << (list.list_of_candidate + i)->math << "    |"
			<< setw(8) << (list.list_of_candidate + i)->literature << "    |"
			<< setw(5) << (list.list_of_candidate + i)->english << "     |"
			<< endl;
		cout << "+-----------------------------------------------------------------------------------------+\n";
	}
	return os;
}
// print list of candidate with total score great than 15
void ListGreatThan15(TestCandidate list) {
	int count = 0;
	cout << "+-----------------------------------------------------------------------------------------+\n";
	cout << "| Srl |    ID    |       Name        | Date of birth |    Math    | Literature |  English |\n";
	cout << "+-----------------------------------------------------------------------------------------+\n";
	for (int i = 0; i < list.number_of_candidate; i++) {
		if(((list.list_of_candidate+i)->english + (list.list_of_candidate + i)->math + (list.list_of_candidate + i)->literature) > 15)
		{
			count++;
			cout << "|"
				<< setw(3) << count << "  |"
				<< setw(9) << (list.list_of_candidate + i)->id << " |"
				<< setw(16) << (list.list_of_candidate + i)->name << "   " << "|"
				<< setw(15) << (list.list_of_candidate + i)->date_of_birth << "" << "|"
				<< setw(8) << (list.list_of_candidate + i)->math << "    |"
				<< setw(8) << (list.list_of_candidate + i)->literature << "    |"
				<< setw(5) << (list.list_of_candidate + i)->english << "     |"
				<< endl;
			cout << "+-----------------------------------------------------------------------------------------+\n";
		}
	}
}
int main() {
	TestCandidate list;
	cin >> list;
	cout << "List of candidate with total score great than 15" << endl;
	ListGreatThan15(list);
	return 0;
}