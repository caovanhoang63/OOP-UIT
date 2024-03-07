#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Sach {
private:
	int id;
	string ten;
	string nxb;
	string loai;
	int gia;
	bool trang_thai;
	int nam_xuat_ban;
	int so_trang;

public:
	// Constructors
	Sach() {
		id = 0;
		gia = 0;
		trang_thai = false;
		nam_xuat_ban = 0;
		so_trang = 0;
	}

	Sach(int _id, string _ten, string _nxb, int _gia, bool _trang_thai, int _nam_xuat_ban, int _so_trang) {
		
		id = _id;
		ten = _ten;
		nxb = _nxb;
		gia = _gia;
		trang_thai = _trang_thai;
		nam_xuat_ban = _nam_xuat_ban;
		so_trang = _so_trang;
	}

	// Getter methods
	int getId() {
		return id;
	}

	string getTen() {
		return ten;
	}

	string getNxb() {
		return nxb;
	}

	string getLoai() {
		return loai;
	}

	int getGia() {
		return gia;
	}

	bool getTrangThai() {
		return trang_thai;
	}

	int getNamXuatBan() {
		return nam_xuat_ban;
	}

	int getSoTrang() {
		return so_trang;
	}

	// Setter methods
	void setId(int _id) {
		id = _id;
	}

	void setTen(string _ten) {
		ten = _ten;
	}

	void setNxb(string _nxb) {
		nxb = _nxb;
	}

	void setLoai(string _loai) {
		loai = _loai;
	}

	void setGia(int _gia) {
		gia = _gia;
	}

	void setTrangThai(bool _trang_thai) {
		trang_thai = _trang_thai;
	}

	void setNamXuatBan(int _nam_xuat_ban) {
		nam_xuat_ban = _nam_xuat_ban;
	}

	void setSoTrang(int _so_trang) {
		so_trang = _so_trang;
	}

	// Input and output methods
	virtual void nhap() {
		cout << "Nhap thong tin sach:" << endl;
		cout << "ID: ";
		cin >> id;
		cin.ignore(); // Ignore the newline character from the previous input
		cout << "Ten: ";
		getline(cin, ten);
		cout << "Nha xuat ban: ";
		getline(cin, nxb);
		cout << "Gia: ";
		cin >> gia;
		cout << "Trang thai (1: Co san, 0: Het hang): ";
		cin >> trang_thai;
		cout << "Nam xuat ban: ";
		cin >> nam_xuat_ban;
		cout << "So trang: ";
		cin >> so_trang;
	}

	virtual void xuat() {
		cout << "Thong tin sach:" << endl;
		cout << "ID: " << id << endl;
		cout << "Ten: " << ten << endl;
		cout << "Nha xuat ban: " << nxb << endl;
		cout << "Loai: " << loai << endl;
		cout << "Gia: " << gia << endl;
		cout << "Trang thai: " << (trang_thai ? "Co san" : "Het hang") << endl;
		cout << "Nam xuat ban: " << nam_xuat_ban << endl;
		cout << "So trang: " << so_trang << endl;
	}
};

class SachGiaoKhoa : public Sach {
private:
	int lop;
	string ten_mon_hoc;

public:
	// Constructors
	SachGiaoKhoa() : Sach() {
		setLoai("SGK");
		lop = 0;
	}
	SachGiaoKhoa(int _id, string _ten, string _nxb,  int _gia, bool _trang_thai, int _nam_xuat_ban, int _so_trang, int _lop, string _ten_mon_hoc)
		: Sach(_id, _ten, _nxb,  _gia, _trang_thai, _nam_xuat_ban, _so_trang) {
		setLoai("SGK");
		lop = _lop;
		ten_mon_hoc = _ten_mon_hoc;
	}

	// Getter methods
	int getLop() {
		return lop;
	}

	string getTenMonHoc() {
		return ten_mon_hoc;
	}

	// Setter methods
	void setLop(int _lop) {
		lop = _lop;
	}

	void setTenMonHoc(string _ten_mon_hoc) {
		ten_mon_hoc = _ten_mon_hoc;
	}

	// Input and output methods
	void nhap() {
		Sach::nhap(); 
		cout << "Lop: ";
		cin >> lop;
		cin.ignore();
		cout << "Ten mon hoc: ";
		getline(cin, ten_mon_hoc);
	}

	void xuat() {
		Sach::xuat();
		cout << "Lop: " << lop << endl;
		cout << "Ten mon hoc: " << ten_mon_hoc << endl;
	}
};
class TieuThuyet : public Sach {
private:
	string the_loai;
	string ten_tac_gia;

public:
	// Constructors
	TieuThuyet() : Sach() {
		setLoai("TieuThuyet");
		the_loai = "";
		ten_tac_gia = "";
	}
	TieuThuyet(int _id, string _ten, string _nxb,  int _gia, bool _trang_thai, int _nam_xuat_ban, int _so_trang, string _the_loai, string _ten_tac_gia)
		: Sach(_id, _ten, _nxb, _gia, _trang_thai, _nam_xuat_ban, _so_trang) {
		setLoai("TieuThuyet");
		the_loai = _the_loai;
		ten_tac_gia = _ten_tac_gia;
	}

	// Getter methods
	string getTheLoai() {
		return the_loai;
	}

	string getTenTacGia() {
		return ten_tac_gia;
	}

	// Setter methods
	void setTheLoai(string _the_loai) {
		the_loai = _the_loai;
	}
	void setTenTacGia(string _ten_tac_gia) {
		ten_tac_gia = _ten_tac_gia;
	}


	// Input and output methods
	void nhap() {
		Sach::nhap(); 
		cin.ignore();
		cout << "The loai: ";
		getline(cin, the_loai);
		cout << "Ten tac gia: ";
		getline(cin, ten_tac_gia);
	}

	void xuat() {
		Sach::xuat(); 
		cout << "The loai: " << the_loai << endl;
		cout << "Ten tac gia: " << ten_tac_gia << endl;
	}
};
class TapChi : public Sach {
private:
	string ten_toa_soan;
	int so_thu_tu;

public:
	// Constructors
	TapChi() : Sach() {
		setLoai("TapChi");
		ten_toa_soan = "";
		so_thu_tu = 0;
	}
	TapChi(int _id, string _ten, string _nxb,  int _gia, bool _trang_thai, int _nam_xuat_ban, int _so_trang, string _ten_toa_soan, int _so_thu_tu)
		: Sach(_id, _ten, _nxb, _gia, _trang_thai, _nam_xuat_ban, _so_trang) {
		setLoai("TapChi");
		ten_toa_soan = _ten_toa_soan;
		so_thu_tu = _so_thu_tu;
	}

	// Getter methods
	string getTenToaSoan() {
		return ten_toa_soan;
	}

	int getSoThuTu() {
		return so_thu_tu;
	}

	// Setter methods
	void setTenToaSoan(string _ten_toa_soan) {
		ten_toa_soan = _ten_toa_soan;
	}

	void setSoThuTu(int _so_thu_tu) {
		so_thu_tu = _so_thu_tu;
	}

	// Input and output methods
	void nhap() {
		Sach::nhap(); 
		cin.ignore();
		cout << "Ten toa soan: ";
		getline(cin, ten_toa_soan);
		cout << "So thu tu: ";
		cin >> so_thu_tu;
	}

	void xuat() {
		Sach::xuat(); 
		cout << "Ten toa soan: " << ten_toa_soan << endl;
		cout << "So thu tu: " << so_thu_tu << endl;
	}
};
class ThuVien {
private:
	vector<Sach*> danhsach;

public:
	void themSach(Sach* sach) {
		danhsach.push_back(sach);
	}
	int tinhTongTienTheoLoai(string loai) {
		int tongTien = 0;
		for (Sach* sach : danhsach) {
			if (sach->getLoai() == loai) {
				tongTien += sach->getGia();
			}
		}
		return tongTien;
	}
	vector<Sach*> timSachTheoTen(string ten) {
		vector<Sach*> sachTimThay;
		for (Sach* sach : danhsach) {
			if (sach->getTen() == ten) {
				sachTimThay.push_back(sach);
			}
		}
		return sachTimThay;
	}
	void thongKeSoLuongSach() {
		int SGK = 0, TieuThuyet = 0, TapChi = 0;
		cout << "Tong so luong sach la : " << danhsach.size() << endl;
		for (auto x : danhsach) {
			if (x->getLoai() == "SGK")
				SGK++;
			else if (x->getLoai() == "TapChi")
				TapChi++;
			else
				TieuThuyet++;
		}
		cout << "So sach giao khoa: " << SGK << endl;
		cout << "So tieu thuyet: " << TieuThuyet << endl;
		cout << "So tap chi: " << TapChi << endl;
	}
	int tinhTongTienCacLoaiSach() {
		int tongTien = 0;
		for (Sach* sach : danhsach) {
			tongTien += sach->getGia();
		}
		return tongTien;
	}
	void nhapDanhSachSach() {
		int n;
		cout << "Nhap so luong sach: ";
		cin >> n;
		cin.ignore(); 
		for (int i = 0; i < n; i++) {
			cout << "Nhap thong tin cho sach thu " << i + 1 << ":" << endl;
			Sach* sach;
			int loai;
			cout << "Nhap loai sach: ( 1 - SGK , 2 -  TieuThuyet ,3 - Tap Chi) ";
			cin >> loai;
			switch (loai)
			{
			case 1 : 
				sach = new SachGiaoKhoa;
				break;
			case 2 :
				sach = new TieuThuyet;
				break;
			case 3:
				sach = new TapChi;
				break;
			default:
				sach = NULL;
				break;
			}
			if (sach == NULL)
				continue;
			sach->nhap();
			themSach(sach);
		}
	}
	void lietKeDanhSachSach() {
		cout << "Danh sach sach trong thu vien:" << endl;
		for (Sach* sach : danhsach) {
			sach->xuat();
			cout << endl;
		}
	}
	void menu() {
		int choice;
		do {
			cout << "---------- MENU ----------" << endl;
			cout << "1. Them sach vao thu vien" << endl;
			cout << "2. Tinh tong tien theo loai sach" << endl;
			cout << "3. Tim sach theo ten" << endl;
			cout << "4. Thong ke so luong sach" << endl;
			cout << "5. Tinh tong tien cac loai sach" << endl;
			cout << "6.Lien ke tat ca cac sach" << endl;
			cout << "0. Thoat" << endl;
			cout << "--------------------------" << endl;
			cout << "Nhap lua chon cua ban: ";
			cin >> choice;
			system("cls");
			switch (choice) {
				case 1:
					nhapDanhSachSach();
					break;
				case 2:
				{

					string loai;
					cout << "Nhap loai sach: ( SGK, TieuThuyet, TapChi): ";
					cin >> loai;
					cout << "Tong tien cac theo loai sach: " << endl;
					cout<<tinhTongTienTheoLoai(loai);
					break;
				}
				case 3:
				{
					string ten;
					cin.ignore();
					cout << "Nhap ten sach: ";
					getline(cin, ten);
					vector<Sach*>result = timSachTheoTen(ten);
					if (result.empty()) {
						cout << "Khong tim thay sach nay! " << endl;
						break;
					}
					for (auto x : result) {
						x->xuat();
					}
					break;
				}
				case 4:
					thongKeSoLuongSach();
					break;
				case 5:
					cout << "Tong tien cua tat ca sach trong thu vien: " << tinhTongTienCacLoaiSach() << endl;
					break;
				case 6:
					lietKeDanhSachSach();
					break;
				case 0:
					cout << "Tam biet!";
					break;
				default:
					cout << "Lua chon khong hop le!"<<endl;
					break;
			}
			cout << endl;
			cout << "Nhan phim Enter de tiep tuc." << endl;
			system("pause");
			system("cls");
		} while (choice != 0);
	}
};

int main() {
	ThuVien UIT;
	Sach* sach1 = new SachGiaoKhoa(1, "Sach Tieng Viet", "Giao Duc", 6000, 1,2004,120,2,"Tieng Viet");
	Sach* sach2 = new TieuThuyet(2, "Sword Art Online", "Kim Dong", 40000, 1, 2020, 250, "LightNovel", "Adachi Shingo");
	Sach* sach3 = new TapChi(3, "Chao Ngay Moi", "Ha Noi", 2000, 1, 2023, 30, "Thanh Nien", 2);
	Sach* sach4 = new TieuThuyet(4, "Sword Art Online", "Kim Dong", 40000, 1, 2020, 250, "LightNovel", "Adachi Shingo");
	UIT.themSach(sach1);
	UIT.themSach(sach2);
	UIT.themSach(sach3);
	UIT.themSach(sach4);
	UIT.menu();
	return 0;
}