#include <iostream>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

bool SetDate(Date &);
void PrintDate(Date);
Date NextDate(Date);
bool isLeapYear(int);

int main() {
	Date date;
	if (!SetDate(date)) {
		cout << "ERROR";
	}else
	{
		PrintDate(NextDate(date));
	}
	return 0;
}

bool SetDate(Date& date) {

	cin >> date.day;
	cin >> date.month;
	cin >> date.year;
	if (date.day <= 0 || date.month <= 0 || date.year < 0)
		return 0;
	if ((!isLeapYear(date.year) && date.month == 2 && date.day == 29) || (date.day >= 32) || date.month >= 13 )
		return 0;
	switch (date.month)
	{
	case 2:
		if (date.day > 29)
			return 0;
	case 4:
	case 6:
	case 9:
	case 11:
		if (date.day == 31)
			return 0;
	}
	return 1;
}
void PrintDate(Date date) {
	cout << date.day << "/" << date.month << "/" << date.year << endl;
}
Date NextDate(Date date) {
	Date nextdate;
	nextdate.year = date.year;
	nextdate.month = date.month;
	switch (date.day)
	{
	case 30:
		switch (date.month)
		{
		case 4:
		case 6:
		case 9:
		case 11:
			nextdate.day = 1;
			nextdate.month++;
			break;
		}
		break;
	case 31:
		switch (date.month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			nextdate.day = 1;
			nextdate.month++;
			break;
		case 12:
			nextdate.day = 1;
			nextdate.month =  1;
			nextdate.year++;
			break;
		}
		break;
	default:
		if (date.month == 2 && (date.day == 28 || date.day == 29)) {
			if ((!isLeapYear(date.year) && date.day == 28) || (isLeapYear(date.year) && date.day == 29)) {
				nextdate.day = 1;
				nextdate.month = 3;
				break;
			}
			else if (isLeapYear(date.year) && date.day == 28) {
				nextdate.day = 29;
				nextdate.month = 2;
				break;
			}
		}
		nextdate.day = ++date.day;
		break;
	}
	return nextdate;
}
bool isLeapYear(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		return 1;
	return 0;
}