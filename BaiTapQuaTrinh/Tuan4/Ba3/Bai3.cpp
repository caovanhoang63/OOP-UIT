#include <iostream>
using namespace std;

class CDate
{
private:
    int day;
    int month;
    int year;

public:
    void Enter();
    void Print();
    CDate NextDay();
    bool isLeapYear();
    int DateDiff(CDate);
    CDate DayBefore();
    int countLeapYear();
};

int main()
{
    CDate a, b;
    a.Enter();
    b.Enter();
    cout << a.DateDiff(b);
    return 0;
}

void CDate::Enter()
{
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Nhap year: ";
    cin >> year;
}

void CDate::Print()
{
    cout << day << "/" << month << "/" << year << endl;
}
bool CDate::isLeapYear()
{
    if (year % 4 == 0 && year % 100 != 0)
        return 1;
    if (year % 400 == 0)
        return 1;
    return 0;
}

CDate CDate::NextDay()
{
    int DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear() == 1)
        DayOfMonth[1] = 29;
    day++;
    if (day > DayOfMonth[month - 1])
    {
        month++;
        if (month > 12)
        {
            year++;
            month = 1;
        }
        day = 1;
    }
    return *this;
}
CDate CDate::DayBefore()
{
    int DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear() == 1)
        DayOfMonth[1] = 29;
    day--;
    if (day == 0)
    {
        month--;
        if (month == 0)
        {
            year--;
            month = 12;
        }
        day = DayOfMonth[month - 1];
    }
    return *this;
}
int CDate::countLeapYear()
{
    int year = this->year;
    if (this->month <= 2)
        year--;
    return year / 4 - year / 100 + year / 400;
}
int CDate::DateDiff(CDate a)
{
    int DayOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total_this = this->day + this->year * 365 + this->countLeapYear();
    int total_a = a.day + a.year * 365 + a.countLeapYear();
    for (int i = 0; i < this->month - 1; i++)
        total_this += DayOfMonth[i];
    for (int i = 0; i < a.month - 1; i++)
        total_a += DayOfMonth[i];
    return abs(total_a - total_this);
}