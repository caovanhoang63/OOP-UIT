#include <iostream>
#include <vector>
using namespace std;
class Diem {
private:
	float x;
	float y;
public:
	Diem() {}
	Diem(float x, float y) {
		this->x = x;
		this->y = y;
	}
	void setX(float x) {
		this->x = x;
	}
	int getX() {
		return x;
	}
	void setY(float y) {
		this->y = y;
	}
	int getY() {
		return y;
	}
	void TinhTien(float a, float b) {
		x = x + a;
		y = y + b;
	}
	friend istream& operator>>(istream& is, Diem& a) {
		cout << "Nhap hoanh do: ";
		is >> a.x;
		cout << "Nhap tung do: ";
		is >> a.y;
		return is;
	}
	friend ostream& operator<<(ostream& os, Diem a) {
		os << "(" << a.x << "," << a.y << ")";
		return os;
	}
	~Diem(){}
};

int main() {
	Diem a;
	cin >> a;
	a.TinhTien(2, 3);
	cout << a;
	return 0;
}