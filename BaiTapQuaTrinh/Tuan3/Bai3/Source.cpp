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
	~Diem() {}
};
class DaGiac {
private:
	int SoDinh;
	Diem* Dinh;
public:
	DaGiac(){}
	DaGiac(int SoDinh,Diem* Dinh){
		this->SoDinh = SoDinh;
		this->Dinh = Dinh;
	}
	friend istream& operator>>(istream& is, DaGiac& dg) {
		while(true)
		{
			cout << "Nhap so dinh: ";
			is >> dg.SoDinh;
			if (dg.SoDinh <= 2)
				cout << "So dinh khong hop le vui long nhap lai!" << endl;
			else {
				break;
			}
		}
		dg.Dinh = new Diem[dg.SoDinh];
		for (int i = 0; i < dg.SoDinh; i++) {
			cout << "Nhap dinh thu " << i+1  << ": "<<endl;
			is >> *(dg.Dinh + i);
		}
		return is;
	}
	friend ostream& operator<<(ostream& os,DaGiac dg) {
		for (int i = 0; i < dg.SoDinh; i++) {
			os << "Toa do dinh thu " << i+1 << ": " << *(dg.Dinh + i) << endl;
		}
		return os;
	}
	void TinhTien(float a, float b) {
		for (int i = 0; i < this->SoDinh; i++) {
			(this->Dinh+i)->TinhTien(a, b);
		}
	}
	void PhongTo(float x) {
		for (int i = 0; i < this->SoDinh; i++) {
			(this->Dinh + i)->setX((this->Dinh + i)->getX() * x);
			(this->Dinh + i)->setY((this->Dinh + i)->getY() * x);
		}
	}
	void ThuNho(float x) {
		for (int i = 0; i < this->SoDinh; i++) {
			(this->Dinh + i)->setX((this->Dinh + i)->getX() / x);
			(this->Dinh + i)->setY((this->Dinh + i)->getY() / x);
		}
	}
	void Quay(float alpha) {
		float rad = alpha * pi / 180;
		for(int i = 0 ; i <SoDinh;i++)
		{
			float x((Dinh+i)->getX() * cos(rad) - (Dinh+i)->getY() * sin(rad));
			float y((Dinh + i)->getY() * cos(rad) + (Dinh + i)->getX() * sin(rad));
			(Dinh + i)->setX(x);
			(Dinh + i)->setY(y);
		}
		
	}
};
int main() {
	DaGiac a;
	cin >> a;
	cout << a;
	return 0;
}