#include "ClassTimeSpan.cpp"
#include <iostream>

class CTime
{
private:
    int _hour = 0;
    int _minute = 0;
    int _second = 0;

public:
    CTime(const CTime &a)
    {
        *this = a;
    }
    CTime(int second = 0, int minute = 0, int hour = 0)
    {
        this->_second = second;
        this->_minute = minute;
        this->_hour = hour;
        this->Reduce();
    }
    // getter
    int GetSecond()
    {
        return _second;
    }
    int GetMinute()
    {
        return _minute;
    }
    int GetHour()
    {
        return _hour;
    }
    // setter
    void SetSecond(int second)
    {
        if (second < 0)
        {
            cout << "Second must be great than zero" << endl;
            return;
        }
        this->_second = second;
    }
    void SetMinute(int minute)
    {
        if (minute < 0)
        {
            cout << "Minute must be great than zero" << endl;
            return;
        }
        this->_minute = minute;
    }
    void SetHour(int hour)
    {
        if (hour < 0)
        {
            cout << "Hour must be great than zero" << endl;
            return;
        }
        this->_hour = hour;
    }
    // nhap
    void Enter();
    // xuat
    void Print() const;
    // xu ly
    void Add(int);
    void Subtract(int);
    TimeSpan Subtract(const CTime &);
    void Increase();
    void Decrease();
    // rut gon
    void Reduce();
    // Giay -> Ctime
    static CTime SecondToCTime(int);
    // CTime -> Giay
    int CTimeToSecond(const CTime &);
};
int main()
{
    CTime a(20, 60, 30);
    a.Print();
    CTime b(19, 30, 1);
    b.Print();
    TimeSpan c = a.Subtract(b);
    c.Print();
    return 0;
}

void CTime::Enter()
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
    this->Reduce();
}
void CTime::Print() const
{
    cout << _second << ":" << _minute << ":" << _hour << endl;
}
void CTime::Add(int second)
{
    this->_second += second;
    this->Reduce();
}
void CTime::Subtract(int second)
{
    int total = CTimeToSecond(*this);
    total -= second;
    if (total < 0)
    {
        cout << "Can't subtract!" << endl;
        return;
    }
    *this = SecondToCTime(total);
}
TimeSpan CTime::Subtract(const CTime &a)
{
    TimeSpan span_this(this->_second, this->_minute, this->_hour);
    TimeSpan span_a(a._second, a._minute, a._hour);
    span_this.Subtract(span_a);
    return span_this;
}
void CTime::Increase()
{
    this->_second++;
    this->Reduce();
}
void CTime::Decrease()
{
    int total = CTimeToSecond(*this);
    total--;
    if (total < 0)
    {
        cout << "Can't decrease!" << endl;
        return;
    }
    *this = SecondToCTime(total);
}
void CTime::Reduce()
{
    if (_second >= 60)
    {
        _minute += _second / 60;
        _second = _second % 60;
    }
    if (_minute >= 60)
    {
        _hour += _minute / 60;
        _minute = _minute % 60;
    }
}

int CTime::CTimeToSecond(const CTime &a)
{
    return _second + 60 * _minute + 3600 * _hour;
}
CTime CTime::SecondToCTime(int second)
{
    CTime temp;
    if (second < 0)
    {
        cout << "Can't convert!" << endl;
        return temp;
    }
    if (second >= 3600)
    {
        temp._hour = second / 3600;
        second = second % 3600;
    }
    if (second >= 60)
    {
        temp._hour = second / 60;
        second = second % 60;
    }
    temp._second = second;
    return temp;
}