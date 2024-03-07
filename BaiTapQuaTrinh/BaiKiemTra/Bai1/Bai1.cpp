#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#define ld long double
class TuyenDuong {
private:
	int maTuyenDuong;
	string tenTuyenDuong;
	int soKM;
public:
	TuyenDuong();
	TuyenDuong(int, string, int);
	TuyenDuong(const TuyenDuong&);
	void Nhap();
	int getMaTuyenDuong() const; 
	string getTenTuyenDuong() const;
	int getSoKM() const;
};
class Xe {
protected:
	string maPhuongTien;
	double trong_tai;
	string noiSanXuat;
	int namSanXuat;
	int tieuhao;
public:
	Xe();
	Xe(string, double, string, int);
	Xe(const Xe&);
	virtual void Nhap();
	string getMaPhuongTien() const;
	int getTrongTai() const;
	string getNoiSanXuat() const;
	int getNSX() const;
	virtual ld tinhCuoc(int) = 0;
};
class Container : public Xe {
public:
	Container();
	Container(string, double, string, int);
	Container(const Container&);
	void Nhap();
	ld tinhCuoc(int);
};
class XeBen : public Xe {
public:
	XeBen();
	XeBen(string, double, string, int);
	XeBen(const XeBen&);
	void Nhap();
	ld tinhCuoc(int);
};
class XeDongLanh : public Xe {
public:
	XeDongLanh();
	XeDongLanh(string, double, string, int);
	XeDongLanh(const XeDongLanh&);
	void Nhap();
	ld tinhCuoc(int);
};
class QuanLyXe {
private:
	int maChuyenHang;
	string maPhuongTien;
	int maTuyenDuong;
	int ngay;
	int thang;
	int nam;
public:
	QuanLyXe();
	QuanLyXe(int, string, int);
	QuanLyXe(const QuanLyXe&);
	void Nhap();
	int getMaChuyenHang() const;
	string getMaPhuongTien() const;
	int getMaTuyenDuong() const;
};
class CongTy {
private:
	vector<Xe*> danhsachXe;
	vector<TuyenDuong> danhsachTuyenDuong;
	vector<QuanLyXe> danhsachChuyenHang;
public:
	CongTy();
	CongTy(vector<Xe*>, vector<TuyenDuong>, vector<QuanLyXe>);
	CongTy(const CongTy&);
	void Nhap();
	ld tinhCuocChuyenXe(int);
	void tinhCuocThang();
	void menu();
};
int main() {
	CongTy a;
	a.menu();
	return 0;
}
TuyenDuong::TuyenDuong() {
	maTuyenDuong = NAN;
	tenTuyenDuong = "";
	soKM = 0;
}
TuyenDuong::TuyenDuong(int ma, string ten, int sokm) {
	this->maTuyenDuong = ma;
	this->tenTuyenDuong = ten;
	this->soKM = sokm;
}
TuyenDuong::TuyenDuong(const TuyenDuong& tuyenduong) {
	*this = tuyenduong;
}
void TuyenDuong::Nhap() {
	cout << "Nhap ma tuyen duong: ";
	cin >> maTuyenDuong;
	cout << "Nhap ten tuyen duong: ";
	cin.ignore();
	getline(cin, tenTuyenDuong);
	cout << "Nhap do dai : ";
	cin >> soKM;
}
int TuyenDuong::getMaTuyenDuong() const {
	return maTuyenDuong;
}
string TuyenDuong::getTenTuyenDuong() const{
	return tenTuyenDuong;
}
int TuyenDuong::getSoKM() const{
	return soKM;
}

Xe::Xe() {
	maPhuongTien = "";
	trong_tai = 0;
	noiSanXuat = "";
	namSanXuat = NAN;
}
Xe::Xe(string ma, double trongtai, string noi, int nam) {
	this->maPhuongTien = ma;
	this->trong_tai = trongtai;
	this->noiSanXuat = noi;
	this->namSanXuat = nam;
}
Xe::Xe(const Xe& xe) {
	*this = xe;
}
void Xe::Nhap() {
	cout << "Nhap ma phuong tien: ";
	cin.ignore();
	getline(cin, maPhuongTien);
	cout << "Nhap noi san xuat: ";
	getline(cin, noiSanXuat);
	cout << "Nhap nam san xuat: ";
	cin >> namSanXuat;
}
string Xe::getMaPhuongTien() const{
	return maPhuongTien;
}
int Xe::getTrongTai() const{
	return trong_tai;
}
string Xe::getNoiSanXuat()  const{
	return noiSanXuat;
}
int Xe::getNSX() const{
	return namSanXuat;
}
Container::Container() {
	tieuhao = 40;
}
Container::Container(string ma, double trongtai, string noi, int nam)
	:Xe(ma, trongtai, noi, nam)
{
	tieuhao = 40;
}
Container::Container(const Container& container) {
	*this = container;
}
void Container::Nhap() {
	Xe::Nhap();
	cout << "Nhap khoi luong hang: ";
	while (cin >> trong_tai) {
		if (trong_tai < 0 || trong_tai> 35)
			cout << "Vuot qua trong tai cho phep, vui long nhap lai! " << endl;
		else
			break;
	}
}
ld Container::tinhCuoc(int quangduong) {
	return trong_tai * 150 * quangduong;
}
XeBen::XeBen() {
	tieuhao = 40;
}
XeBen::XeBen(string ma, double trongtai, string noi, int nam)
	:Xe(ma, trongtai, noi, nam)
{
	tieuhao = 40;
}
XeBen::XeBen(const XeBen& xeben) {
	*this = xeben;
}
void XeBen::Nhap() {
	Xe::Nhap();
	cout << "Nhap khoi luong hang: ";
	while (cin >> trong_tai) {
		if (trong_tai < 0 || trong_tai> 20)
			cout << "Vuot qua trong tai cho phep, vui long nhap lai! " << endl;
		else
			break;
	}
}
ld XeBen::tinhCuoc(int quangduong) {
	return trong_tai * 5000 * quangduong;
}
XeDongLanh::XeDongLanh() {
	tieuhao = 25;
}
XeDongLanh::XeDongLanh(string ma, double trongtai, string noi, int nam)
	:Xe(ma, trongtai, noi, nam)
{
	tieuhao = 25;
}
XeDongLanh::XeDongLanh(const XeDongLanh& xe) {
	*this = xe;
}
void XeDongLanh::Nhap() {
	Xe::Nhap();
	cout << "Nhap trong tai: ";
	while (cin >> trong_tai) {
		if (trong_tai < 0 || trong_tai> 3.5)
			cout << "Vuot qua trong tai cho phep, vui long nhap lai! " << endl;
		else
			break;
	}
}
ld XeDongLanh::tinhCuoc(int quangduong) {
	return trong_tai * 200 * quangduong;
}

QuanLyXe::QuanLyXe() {
	maChuyenHang = NAN;
	maPhuongTien = "";
	maTuyenDuong = NAN;
}
QuanLyXe::QuanLyXe(int machuyen, string maxe, int matuyen) {
	this->maChuyenHang = machuyen;
	this->maPhuongTien = maxe;
	this->maTuyenDuong = matuyen;
}
QuanLyXe::QuanLyXe(const QuanLyXe& chuyen) {
	*this = chuyen;
}
void QuanLyXe::Nhap() {
	cout << "Nhap ma chuyen hang ";
	cin >> maChuyenHang;
	cout << "Nhap ma phuong tien: ";
	cin.ignore();
	getline(cin, maPhuongTien);
	cout << "Nhap ma tuyen duong: ";
	cin >> maTuyenDuong;
	cout << "Nhap thoi gian xuat phat: " << endl;
	cout << "Nhap ngay: ";
	cin >> ngay;
	cout << "Nhap thang: ";
	cin >> thang;
	cout << "Nhap nam: ";
	cin >> nam;
}
int QuanLyXe::getMaChuyenHang()const {
	return maChuyenHang;
}
string QuanLyXe::getMaPhuongTien() const{
	return maPhuongTien;
}
int QuanLyXe::getMaTuyenDuong()  const {
	return maTuyenDuong;
}
CongTy::CongTy() {
	return;
}
CongTy::CongTy(vector<Xe*> danhsachxe, vector<TuyenDuong> danhsachtuyen, vector<QuanLyXe> danhsachchuyen) {
	this->danhsachXe = danhsachxe;
	this->danhsachTuyenDuong = danhsachtuyen;
	this->danhsachChuyenHang = danhsachchuyen;
}
CongTy::CongTy(const CongTy& temp) {
	for (Xe* x : temp.danhsachXe) {
		this->danhsachXe.push_back(x);
	}
	this->danhsachTuyenDuong = temp.danhsachTuyenDuong;
	this->danhsachChuyenHang = temp.danhsachChuyenHang;
}
void CongTy::Nhap() {
	int soxe, sotuyen, sochuyen, loaixe;
	cout << "Nhap so luong xe ";
	cin >> soxe;
	danhsachXe.resize(soxe);
	for (Xe*& xe : danhsachXe) {
		cout << "Nhap loai xe (1 - Container, 2 - Xe Ben, 3 - Xe Dong Lanh): ";
		cin >> loaixe;
		switch (loaixe)
		{
		case 1:
			xe = new Container;
			break;
		case 2:
			xe = new XeBen;
			break;
		case 3:
			xe = new XeDongLanh;
			break;
		default:
			xe = NULL;
			break;
		}
		if (xe != NULL) {
			xe->Nhap();
		}
	}
	cout << "Nhap so tuyen duong: ";
	cin >> sotuyen;
	danhsachTuyenDuong.resize(sotuyen);
	for (TuyenDuong& tuyen : danhsachTuyenDuong) {
		tuyen.Nhap();
	}
	cout << "Nhap so chuyen xe: ";
	cin >> sochuyen;
	danhsachChuyenHang.resize(sochuyen);
	for (QuanLyXe& chuyen : danhsachChuyenHang) {
		chuyen.Nhap();
	}
}

ld CongTy::tinhCuocChuyenXe(int machuyen) {
	string ma_xe = "";
	int ma_tuyen = NAN;
	for (QuanLyXe chuyen : danhsachChuyenHang) {
		if (machuyen == chuyen.getMaChuyenHang()) {
			ma_xe = chuyen.getMaPhuongTien();
			ma_tuyen = chuyen.getMaTuyenDuong();
			break;
		}
	}
	for (Xe* xe : danhsachXe) {
		if (xe->getMaPhuongTien() == ma_xe) {
			for (TuyenDuong tuyen : danhsachTuyenDuong) {
				if (tuyen.getMaTuyenDuong() == ma_tuyen) {
					return xe->tinhCuoc(tuyen.getSoKM());
				}
			}
		}
	}
	return 0;
}
void CongTy::tinhCuocThang() {
	map<string, ld> totalCosts;
	for (const QuanLyXe& chuyen : danhsachChuyenHang) {
		string ma_xe = chuyen.getMaPhuongTien();
		int ma_tuyen = chuyen.getMaTuyenDuong();
		Xe* xe = nullptr;
		for (Xe* tempXe : danhsachXe) {
			if (tempXe->getMaPhuongTien() == ma_xe) {
				xe = tempXe;
				break;
			}
		}
		const TuyenDuong* tuyen = nullptr;
		for (const TuyenDuong& tempTuyen : danhsachTuyenDuong) {
			if (tempTuyen.getMaTuyenDuong() == ma_tuyen) {
				tuyen = &tempTuyen;
				break;
			}
		}
		if (xe != nullptr && tuyen != nullptr) {
			ld cuoc = xe->tinhCuoc(tuyen->getSoKM());
			totalCosts[ma_xe] += cuoc;
		}
	}
	for (const auto& pair : totalCosts) {
		cout << "Ma phuong tien: " << pair.first << ", Tong cuoc: " << pair.second << endl;
	}
}
void CongTy::menu() {
	int chucnang;
	do
	{
		cout << "Chon chuc nang" << endl;
		cout << "0 - Ket thuc " << endl;
		cout << "1 - Nhap " << endl;
		cout << "2 - Tinh cuoc cho chuyen hang" << endl;
		cout << "3- Thong ke cuoc cua moi xe" << endl;
		cin >> chucnang;
		switch (chucnang)
		{
		case 0:
			break;
		case 1:
			Nhap();
			break;
		case 2:
		{
			int machuyen;
			cout << "Nhap ma chuyen hang: ";
			cin >> machuyen;
			ld cuoc = tinhCuocChuyenXe(machuyen);
			cout << "Tien cuoc cua chuyen xe la: " << cuoc << endl;
			break;
		}
		case 3:
			tinhCuocThang();
			break;
		default:
			cout << "Chuc nang khong ton tai!";
			break;
		}
	} while (chucnang != 0);
}