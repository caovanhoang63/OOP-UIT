#include <iostream>
#include <vector>
using namespace std;

class NhomMau {
private:
	int loai; // 1 - O , 2 - A , 3 - B , 4 - AB
	bool rh;
public:
	void Nhap();
	int getLoai();
	bool getRH();
	void setLoai(int);
	virtual bool KiemTraDiTruyen(NhomMau* cha, NhomMau* me) = 0;
	virtual bool NhanMau(NhomMau*) = 0;
};
class NhomO : public NhomMau{
public:
	bool KiemTraDiTruyen(NhomMau* cha, NhomMau* me);
	bool NhanMau(NhomMau*);
};
class NhomA : public NhomMau {
public:
	bool KiemTraDiTruyen(NhomMau* cha, NhomMau* me);
	bool NhanMau(NhomMau*);
};
class NhomB : public NhomMau {
public:
	bool KiemTraDiTruyen(NhomMau* cha, NhomMau* me);
	bool NhanMau(NhomMau*);
};
class NhomAB : public NhomMau {
public:
	bool KiemTraDiTruyen(NhomMau* cha, NhomMau* me);
	bool NhanMau(NhomMau*);
};
class QuanLy {
private:
	vector<NhomMau*> danhsach;
public:
	void Nhap();
	NhomMau* NhapNhomMau();
	bool KiemTraDiTruyen(NhomMau* con,NhomMau* cha, NhomMau* me);
	void DanhSachChoMau();
	void menu();
};
int main() {
	QuanLy aaa;
	aaa.menu();
	return 0;
}

void NhomMau::setLoai(int loai) {
	this->loai = loai;
}
void NhomMau::Nhap() {
	cout << "Nhap chi so rh ( 1 : + , 0 : -): ";
	cin >> rh;
}
int NhomMau::getLoai() {
	return loai;
}
bool NhomMau::getRH() {
	return rh;
}
bool NhomO::KiemTraDiTruyen(NhomMau* cha, NhomMau* me) {
	if (cha->getLoai() == 4 || me->getLoai() == 4)
		return 0;
	return 1;
}
bool NhomA::KiemTraDiTruyen(NhomMau* cha, NhomMau* me) {
	if (cha->getLoai() == 1 && me->getLoai() == 3) return false;
	if (cha->getLoai() == 3 && me->getLoai() == 1) return false;
	if (cha->getLoai() == 1 && me->getLoai() == 1)return false;
	return true;
}
bool NhomB::KiemTraDiTruyen(NhomMau* cha, NhomMau* me) {
	if (cha->getLoai() == 1 && me->getLoai() == 2) return false;
	if (cha->getLoai() == 2 && me->getLoai() == 1) return false;
	if (cha->getLoai() == 1 && me->getLoai() == 1)return false;
	return true;
}
bool NhomAB::KiemTraDiTruyen(NhomMau* cha, NhomMau* me) {
	if (cha->getLoai() == 4 || me->getLoai() == 4) return true;
	if (cha->getLoai() == 2 && me->getLoai() == 3) return true;
	if (cha->getLoai() == 3 && me->getLoai() == 2) return true;
	return false;
}
bool NhomO::NhanMau(NhomMau* temp) {
	if (!this->getRH() && temp->getRH())
		return 0;
	else {
		if (temp->getLoai() == 1)
			return 1;
		return 0;
	}
}

bool NhomA::NhanMau(NhomMau* temp) {
	if (!this->getRH() && temp->getRH())
		return 0;
	else {
		int loai = temp->getLoai();
		if (loai == 1 || loai == 2)
			return 1;
		return 0;
	}
}
bool NhomB::NhanMau(NhomMau* temp) {
	if (!this->getRH() && temp->getRH())
		return 0;
	else {
		int loai = temp->getLoai();
		if (loai == 1 || loai == 3)
			return 1;
		return 0;
	}
}
bool NhomAB::NhanMau(NhomMau* temp) {
	if (!this->getRH() && temp->getRH())
		return 0;
	else {
		return 1;
	}
}
void QuanLy::Nhap() {
	cout << "Nhap so nguoi: ";
	int n;
	cin >> n;
	danhsach.resize(n);
	for (NhomMau*& x : danhsach) {
		x = NhapNhomMau();
	}
}
NhomMau* QuanLy::NhapNhomMau() {
	int loai;
	NhomMau* x;
	cout << "Nhap nhom mau (1 - O, 2 - A, 3 - B, 4 - AB): ";
	cin >> loai;
	switch (loai)
	{
	case 1:
		x = new NhomO;
		break;
	case 2:
		x = new NhomA;
		break;
	case 3:
		x = new NhomB;
		break;
	case 4:
		x = new NhomAB;
	default:
		x = NULL;
		break;
	}
	if (x != NULL) {
		x->Nhap();
		x->setLoai(loai);
	}
	return x;
}
void QuanLy::DanhSachChoMau() {
	cout << "Nhap stt cua nguoi can truyen mau: ";
	int stt;
	cin >> stt;
	cout << "Stt cua nhung nguoi co the cho mau la: ";
	for (int i = 0; i < danhsach.size(); i++) {
		if (i != stt)
			if (danhsach[stt]->NhanMau(danhsach[i]))
				cout << i << " ";
	}
	cout << endl;
}
bool QuanLy::KiemTraDiTruyen(NhomMau* con,NhomMau* cha, NhomMau *me) {
	return con->KiemTraDiTruyen(cha, me);
}
void QuanLy::menu() {
	int chucnang;
	do
	{
		cout << "Chon chuc nang " << endl;
		cout << "1 - Nhap danh sach " << endl;
		cout << "2 - Kiem tra danh sach cho mau " << endl;
		cout << "3 - Kiem tra di truyen" << endl;
		cout << "0 - Ket Thuc" << endl;
		cin >> chucnang;
		switch (chucnang)
		{
		case 1:
			Nhap();
			break;
		case 2:
			DanhSachChoMau();
			break;
		case 3:
		{
			NhomMau* cha, * me, * con;
			cout << "Nhap thong tin nguoi con: "<<endl;
			con = NhapNhomMau();
			cout << "Nhap thong tin cha: "<<endl;
			cha = NhapNhomMau();
			cout << "Nhap thong tin me: "<<endl;
			me = NhapNhomMau();
			if (KiemTraDiTruyen(con, cha, me))
				cout << "con co kha nang cung huyet thong voi cha me!" << endl;
			else
				cout << "con khong cung huyet thong voi cha me!" << endl;
			break;
		}
		case 0:
			break;
		default:
			cout << "Chuc nang khong ton tai, vui long nhap lai! " << endl;
			break;
		}
	} while (chucnang != 0);

	 
}