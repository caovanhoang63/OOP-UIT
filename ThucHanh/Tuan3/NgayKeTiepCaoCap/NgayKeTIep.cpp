#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() {};
    void Enter() {
        cin >> this->day>>this->month>>this->year;
        day = abs(day);
        month = abs(month);
        year = abs(year);
        this->month = (this->month) % 12; if (this->month == 0) this->month = 12;
        if (this->day > CheckDayOfmonth())
        {
            this->day = 1;
        }
    }
    int CheckDayOfmonth() {
        int DayOfmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (isLeapYear())
            DayOfmonth[1] = 29;
        return DayOfmonth[month - 1];
    }
    bool isLeapYear() {
        if (year % 4 == 0 && year % 100 != 0)
            return 1;
        if (year % 400 == 0 && year %100 == 0)
            return 1;
        return 0;
    }
    void operator++() {
        int DayOfmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear() == 1)
            DayOfmonth[1] = 29;
        day++;
        if (day > DayOfmonth[month - 1])
        {
            month++;
            if (month > 12)
            {
                year++;
                month = 1;
            }
            day = 1;
        }
    }
    void operator--() {
        int DayOfmonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (isLeapYear() == 1)
            DayOfmonth[1] = 29;
        day--;
        if (day==0)
        {
            month--;
            if (month == 0)
            {
                year--;
                month = 12;
            }
            day = 31;
        }
    }
    int countLeapYear()
    {
        int year = this->year;
        if (this->month <= 2)
            year--;
        return year / 4 - year / 100 + year / 400;
    }
    int Daydiff(Date a) {
        int DayOfMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int total_this = this->day + this->year * 365 + this->countLeapYear();
        int total_a = a.day + a.year * 365 + a.countLeapYear();
        for (int i = 0; i < this->month - 1; i++)
            total_this += DayOfMonth[i];
        for (int i = 0; i < a.month - 1; i++)
            total_a += DayOfMonth[i];
        return abs(total_a - total_this);
    }
};

int main() {
    int n;
    Date first;
    first.Enter();
    while (true) {
        cin >> n;
        switch (n)
        {
        case 1:
        {
            int x;
            cin >> x;
            if (x < 0) {
                x = abs(x);
                for (int i = 0; i < x; i++)
                    --first;
                break;
            }
            for (int i = 0; i < x; i++)
                ++first;
            break;
        }
        case 2:
        {
            int x;
            cin >> x;
            if (x < 0) {
                x = abs(x);
                for (int i = 0; i < x; i++)
                    ++first;
                break;
            }
            for (int i = 0; i < x; i++)
                --first;
            break;
        }
        case 3:
        {
            Date second;
            second.Enter();
            cout << first.Daydiff(second);
            break;
        }
        default:
            break;
        }
        if (n == 3)
            break;
    }
    return 0;
}