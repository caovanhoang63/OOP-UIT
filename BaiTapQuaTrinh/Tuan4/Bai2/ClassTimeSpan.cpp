#include <iostream>
#include <iomanip>
using namespace std;

class TimeSpan
{
private:
    int _year = 0;
    int _month = 0;
    int _day = 0;
    int _hour = 0;
    int _minute = 0;
    int _second = 0;

public:
    // Constructor
    TimeSpan(const TimeSpan &);
    TimeSpan(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
    // Nhap
    void Enter();
    // getter
    int GetSecond() const
    {
        return _second;
    }
    int GetMinute() const
    {
        return _minute;
    }
    int GetHour() const
    {
        return _hour;
    }
    int GetDay() const
    {
        return _day;
    }
    int GetMonth() const
    {
        return _month;
    }
    int GetYear() const
    {
        return _year;
    }
    // setter
    void SetSecond(int second)
    {
        if (second < 0)
        {
            cout << "Second must be great than zero!" << endl;
            return;
        }
        this->_second = second;
    }
    void SetMinute(int minute)
    {
        if (minute < 0)
        {
            cout << "Minute must be great than zero!" << endl;
            return;
        }
        this->_minute = minute;
    }
    void SetHour(int hour)
    {
        if (hour < 0)
        {
            cout << "Minute must be great than zero!" << endl;
            return;
        }
        this->_hour = hour;
    }
    void SetDay(int day)
    {
        if (day < 0)
        {
            cout << "Day must be great than zero!" << endl;
            return;
        }
        this->_day = day;
    }
    void SetMonth(int month)
    {
        if (month < 0)
        {
            cout << "Month must be great than zero!" << endl;
            return;
        }
        this->_month = month;
    }
    void SetYear(int year)
    {
        if (year < 0)
        {
            cout << "Year must be great than zero!" << endl;
            return;
        }
        this->_year = year;
    }
    // Xuat
    void Print();
    // Rut Gon
    void Reduce();
    // Tinh toan
    void Add(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
    void Subtract(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
    bool EqualTo(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    bool Diffrent(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    bool GreatThan(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    bool GreatThanOrEqualTo(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    bool LessThan(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    bool LessThanOrEqualTo(int = 0, int = 0, int = 0, int = 0, int = 0, int = 0) const;
    void Add(const TimeSpan &);
    void Subtract(const TimeSpan &);
    bool EqualTo(const TimeSpan &);
    bool Diffrent(const TimeSpan &) const;
    bool GreatThan(const TimeSpan &) const;
    bool GreatThanOrEqualTo(const TimeSpan &) const;
    bool LessThan(const TimeSpan &) const;
    bool LessThanOrEqualTo(const TimeSpan &) const;
    // Destuctor
    ~TimeSpan() {}
};
// second : minute : hour : day : month : year
// 1 month  = 30 day

TimeSpan::TimeSpan(int second, int minute, int hour, int day, int month, int year)
{

    this->_year = year;
    this->_month = month;
    this->_day = day;
    this->_hour = hour;
    this->_minute = minute;
    this->_second = second;
    this->Reduce();
}
void TimeSpan::Reduce()
{
    if (this->_second >= 60)
    {
        this->_minute += this->_second / 60;
        this->_second = this->_second % 60;
    }
    if (this->_minute >= 60)
    {
        this->_hour += this->_minute / 60;
        this->_minute = this->_minute % 60;
    }
    if (this->_hour >= 24)
    {
        this->_day += this->_hour / 24;
        this->_hour = this->_hour % 24;
    }
    if (this->_day >= 30)
    {
        this->_month += this->_day / 30;
        this->_day = this->_day % 30;
    }
    if (this->_month >= 12)
    {
        this->_year += this->_month / 12;
        this->_year = this->_year % 12;
    }
}
void TimeSpan::Enter()
{
    int x;
    cout << "Nhap so giay: ";
    cin >> x;
    while (x < 0)
    {
        cout << "So giay khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _second = x;
    cin >> x;
    while (x < 0)
    {
        cout << "So phut khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _minute = x;
    cin >> x;
    while (x < 0)
    {
        cout << "So gio khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _hour = x;
    cin >> x;
    while (x < 0)
    {
        cout << "So ngay khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _day = x;
    while (x < 0)
    {
        cout << "So thang khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _month = x;
    cin >> x;
    while (x < 0)
    {
        cout << "So nam khong hop le, vui long nhap lai!";
        cin >> x;
    }
    _year = x;
    this->Reduce();
}
TimeSpan::TimeSpan(const TimeSpan &a)
{
    *this = a;
}
void TimeSpan::Print()
{
    cout << this->_second << ":" << this->_minute << ":" << this->_hour << ":" << this->_day << ":" << this->_month << ":" << this->_year << endl;
}
void TimeSpan::Add(int second, int minute, int hour, int day, int month, int year)
{

    this->_year += year;
    this->_month += month;
    this->_day += day;
    this->_hour += hour;
    this->_minute += minute;
    this->_second += second;
    this->Reduce();
}
void TimeSpan::Subtract(int second, int minute, int hour, int day, int month, int year)
{
    int total = second + minute * 60 + hour * 3600 + day * 24 * 3600 + month * 30 * 24 * 3600 + year * 365 * 24 * 3600;
    int total_this = this->_second + this->_minute * 60 + this->_hour * 3600 + this->_day * 24 * 3600 + this->_month * 30 * 24 * 3600 + this->_year * 365 * 24 * 3600;
    int result = total_this - total;
    TimeSpan temp(0, 0, 0, 0, 0, 0);
    *this = temp;
    if (result < 0)
    {
        cout << "Can't subtract" << endl;
        return;
    }
    if (result >= 365 * 24 * 3600)
    {
        this->_year = result % 365 * 24 * 3600;
        result = result % 365 * 24 * 3600;
    }
    if (result >= 30 * 24 * 3600)
    {
        this->_month = result % 24 * 30 * 3600;
        result = result % 24 * 30 * 3600;
    }
    if (result >= 24 * 3600)
    {
        this->_day = result % 24 * 3600;
        result = result % 24 * 3600;
    }
    if (result >= 3600)
    {
        this->_hour = result % 3600;
        result = result % 3600;
    }
    if (result >= 60)
    {
        this->_minute = result % 60;
        result = result % 60;
    }
    this->_second = result;
}
bool TimeSpan::EqualTo(int second, int minute, int hour, int day, int month, int year) const
{
    if (second != this->_second || minute != this->_minute || hour != this->_hour ||
        day != this->_day || month != this->_month || year != this->_year)
        return 0;
    return 1;
}
bool TimeSpan::Diffrent(int second, int minute, int hour, int day, int month, int year) const
{
    if (second == this->_second || minute == this->_minute || hour == this->_hour ||
        day == this->_day || month == this->_month || year == this->_year)
        return 0;
    return 1;
}
bool TimeSpan::GreatThan(int second, int minute, int hour, int day, int month, int year) const
{
    if (second > this->_second && minute > this->_minute && hour > this->_hour &&
        day > this->_day && month > this->_month && year > this->_year)
        return 1;
    return 0;
}
bool TimeSpan::GreatThanOrEqualTo(int second, int minute, int hour, int day, int month, int year) const
{
    if (second >= this->_second && minute >= this->_minute && hour >= this->_hour &&
        day >= this->_day && month >= this->_month && year >= this->_year)
        return 1;
    return 0;
}
bool TimeSpan::LessThan(int second, int minute, int hour, int day, int month, int year) const
{
    if (second < this->_second && minute < this->_minute && hour < this->_hour &&
        day < this->_day && month < this->_month && year < this->_year)
        return 1;
    return 0;
}
bool TimeSpan::LessThanOrEqualTo(int second, int minute, int hour, int day, int month, int year) const
{
    if (second <= this->_second && minute <= this->_minute && hour <= this->_hour &&
        day <= this->_day && month <= this->_month && year <= this->_year)
        return 1;
    return 0;
}
void TimeSpan::Add(const TimeSpan &a)
{

    this->_year += a._year;
    this->_month += a._month;
    this->_day += a._day;
    this->_hour += a._hour;
    this->_minute += a._minute;
    this->_second += a._second;
    this->Reduce();
}
void TimeSpan::Subtract(const TimeSpan &a)
{
    int total_a = a._second + a._minute * 60 + a._hour * 3600 + a._day * 24 * 3600 + a._month * 30 * 24 * 3600 * a._year * 365 * 24 * 3600;
    int total_this = this->_second + this->_minute * 60 + this->_hour * 3600 + this->_day * 24 * 3600 + this->_month * 30 * 24 * 3600 * this->_year * 365 * 24 * 3600;
    int result = total_this - total_a;
    if (result < 0)
    {
        cout << "Can't subtract" << endl;
        return;
    }
    TimeSpan temp(0, 0, 0, 0, 0, 0);
    *this = temp;
    if (result >= (365 * 24 * 3600))
    {
        this->_year = result / (365 * 24 * 3600);
        result = result % (365 * 24 * 3600);
    }
    if (result >= (30 * 24 * 3600))
    {
        this->_month = result / (24 * 30 * 3600);
        result = result % (24 * 30 * 3600);
    }
    if (result >= (24 * 3600))
    {
        this->_day = result / (24 * 3600);
        result = result % (24 * 3600);
    }
    if (result >= 3600)
    {
        this->_hour = result / 3600;
        result = result % 3600;
    }
    if (result >= 60)
    {
        this->_minute = result / 60;
        result = result % 60;
    }
    this->_second = result;
}
bool TimeSpan::EqualTo(const TimeSpan &a)
{
    if (a._second != this->_second || a._minute != this->_minute || a._hour != this->_hour ||
        a._day != this->_day || a._month != this->_month || a._year != this->_year)
        return 0;
    return 1;
}
bool TimeSpan::Diffrent(const TimeSpan &a) const
{
    if (a._second == this->_second || a._minute == this->_minute || a._hour == this->_hour ||
        a._day == this->_day || a._month == this->_month || a._year == this->_year)
        return 0;
    return 1;
}
bool TimeSpan::GreatThan(const TimeSpan &a) const
{
    if (a._second > this->_second && a._minute > this->_minute && a._hour > this->_hour &&
        a._day > this->_day && a._month > this->_month && a._year > this->_year)
        return 1;
    return 0;
}
bool TimeSpan::GreatThanOrEqualTo(const TimeSpan &a) const
{
    if (a._second >= this->_second && a._minute >= this->_minute && a._hour >= this->_hour &&
        a._day >= this->_day && a._month >= this->_month && a._year >= this->_year)
        return 1;
    return 0;
}
bool TimeSpan::LessThan(const TimeSpan &a) const
{
    if (a._second < this->_second && a._minute < this->_minute && a._hour < this->_hour &&
        a._day < this->_day && a._month < this->_month && a._year < this->_year)
        return 1;
    return 0;
}
bool TimeSpan::LessThanOrEqualTo(const TimeSpan &a) const
{
    if (a._second <= this->_second && a._minute <= this->_minute && a._hour <= this->_hour &&
        a._day <= this->_day && a._month <= this->_month && a._year <= this->_year)
        return 1;
    return 0;
}