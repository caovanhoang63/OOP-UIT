#include <iostream>

using namespace std;

class PhanSo {
public:
	int tu;
	int mau;
	PhanSo() {

	}
	PhanSo(int x) {
		this->tu = x;
		this->mau = 1;
	}
	PhanSo(int x ,int y) {
		this->tu = x;
		this->mau = y;
	}
	PhanSo(const PhanSo& temp) {
		*this = temp;
	}
	friend ostream& operator<<(ostream& os, const PhanSo& a) {
		os << a.tu << "/" << a.mau;
		return os;
	}
	PhanSo operator+(PhanSo a) {
		PhanSo tong;
		tong.tu = this->tu + a.tu;
		tong.mau = this->mau + a.mau;
		return tong;
	}
	~PhanSo() {

	}
};
class a {
public:
	int size;
	int* A;
	a& operator=(const a& temp){
		this->A = new int[temp.size];
		for (int i = 0; i < temp.size; i++) {
			this->A[i] = temp.A[i];
		}
		
		return *this;
	}
};
class cha {
public:
	cha() {
		cout << "Day la ham tao cua lop cha" << endl;
	}
	~cha() {
		cout << "huy cha" << endl;
	}
};
class con : public cha {
public:
	int x;
	con() {
		cout << "Day la ham tao cua lop con" << endl;
	}
	con(int x) {
		cout << "Day la ham tao co doi so" << endl;
		this->x = x;
	}
	~con() {
		cout << "Huy con" <<x << endl;
	}
};

int main() {
	con b;
	con a(1);
	b.x = 2;
	return 0;
}


