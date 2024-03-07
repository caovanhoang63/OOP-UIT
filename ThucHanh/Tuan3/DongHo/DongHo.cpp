#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Clock {
private:
    int second;
    int minute;
    int hour;
public:
    Clock() {}
    void Enter() {
        cin >> hour >> minute >> second;
        hour = abs(hour);
        minute = abs(minute);
        second = abs(second);
        if (second > 60)
            second = second % 60;
        if (minute > 60)
            minute = minute % 60;
        if (hour >= 24)
            hour = hour % 24;
    }
    void operator++(int) {
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
            }
        }
        if (hour >= 24)
            hour = hour % 24;
    }
    void operator--(int) {
        second--;
        if (second == -1)
        {
            second = 59;
            minute--;
            if (minute == -1) {
                minute = 59;
                hour--;
            }
        }
        if (hour >= 24)
            hour = hour % 24;
    }
    void operator+=(int x) {
        second += x;
        if (second >= 60) {
            minute += second / 60;
            second = second % 60;
            if (minute >= 60) {
                hour += minute / 60;
                minute = minute % 60;
            }
        }
        if (hour >= 24)
            hour = hour % 24;
    }
    void operator-=(int x) {
        second -= x;
        if (second < 0) {
            minute -= 1;
            second += 60;
            if (minute < 0) {
                hour -= minute / 60;
                minute += 60;
            }
        }
        if (hour >= 24)
            hour = hour % 24;
    }
    void Print() {
        cout << hour << " " << minute << " " << second << " " << endl;
    }
};

int main() {
    Clock a;
    a.Enter();
    int n;
    cin >> n;
    string lenh;
    for (int i = 0; i < n; i++) {
        cin >> lenh;
        if (lenh == "++")
        {
            a++;
            continue;
        }
        if (lenh == "--")
        {
            a--;
            continue;
        }
        if (lenh == "+") {
            int x;
            cin >> x;
            if (x < 0) {
                x = abs(x);
                a -= x;
                continue;
            }
            a += x;
            continue;
        }
        if (lenh == "-") {
            int x;
            cin >> x;
            if (x < 0) {
                x = abs(x);
                a += x;
                continue;
            }
            a -= x;
            continue;
        }
    }
    a.Print();
    return 0;
}