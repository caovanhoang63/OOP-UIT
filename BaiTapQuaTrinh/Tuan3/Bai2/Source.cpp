#include <iostream>
const float pi = 3.141592654;
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
class TamGiac {
private:
	Diem A, B, C;
public:
	TamGiac() {}
	TamGiac(Diem A,Diem B,Diem C) {
		this->A = A;
		this->B = B;
		this->C = C;
	}
	TamGiac(float x1, float y1, float x2, float y2, float x3, float y3) {
		this->A.setX(x1);
		this->A.setX(y1);
		this->B.setX(x2);
		this->B.setX(y2);
		this->C.setX(x3);
		this->C.setX(y3);
	}
	friend istream& operator>>(istream& is, TamGiac& tg) {
		cout << "Nhap toa do dinh thu nhat: " <<endl;
		is >> tg.A;
		cout << "Nhap toa do dinh thu hai:  "<<endl;
		is >> tg.B;
		cout << "Nhap toa do dinh thu ba :   "<< endl;
		is >> tg.C;
		return is;
	}
	friend ostream& operator<<(ostream& os, TamGiac tg) {
		os << "Toa do dinh thu nhat: "<<tg.A<<endl;
		os << "Toa do dinh thu hai : "<<tg.B<<endl;
		os << "Toa do dinh thu ba  : "<<tg.C<<endl;
		return os;
	}
	void TinhTien(float a, float b) {
		A.TinhTien(a, b);
		B.TinhTien(a, b);
		B.TinhTien(a, b);
	}
	void PhongTo(float x) {
		A.setX(A.getX() * x);
		A.setY(A.getY() * x);
		B.setX(B.getX() * x);
		B.setY(B.getY() * x);
		C.setX(C.getX() * x);
		C.setY(C.getY() * x);
	}
	void ThuNho(float x) {
		A.setX(A.getX() / x);
		A.setY(A.getY() / x);
		B.setX(B.getX() / x);
		B.setY(B.getY() / x);
		C.setX(C.getX() / x);
		C.setY(C.getY() / x);
	}
	void Quay(float alpha) {
		float rad = alpha * pi / 180;
		float xa(A.getX() * cos(rad) - A.getY() * sin(rad));
		float ya(A.getY() * cos(rad) + A.getX() * sin(rad));
		A.setX(xa);
		A.setY(ya);
		float xb(B.getX() * cos(rad) - B.getY() * sin(rad));
		float yb(B.getY() * cos(rad) + B.getX() * sin(rad));
		B.setX(xb);
		B.setY(yb);
		float xc(C.getX() * cos(rad) - C.getY() * sin(rad));
		float yc(C.getY() * cos(rad) + C.getX() * sin(rad));
		A.setX(xc);
		A.setY(yc);
	}
};
int main() {
	TamGiac tg;
	cin >> tg;
	cout << tg;
	return 0;
}