#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class  MYINT {
private:
    int a;
public:
    MYINT(int a) {
        this->a = a;
    }
    MYINT operator+(MYINT &b) {
        MYINT temp(0);
        temp.a  = this->a - b.a;
        return temp;
    }
    MYINT operator*(MYINT &b) {
        MYINT temp(0);
        temp.a = this->a * b.a;
        return temp;
    }
    friend ostream& operator<<(ostream& os,MYINT a) {
        os << a.a<<endl;
        return os;
    }
    
};

int main() {
    MYINT a(4), b(5);
    cout << (a + b) * a;
    cout << a * b;
    return 0;
}
