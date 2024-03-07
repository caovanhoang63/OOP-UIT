#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


class GiaSuc {
protected:
	int san_luong_sua;
	int id;
public:
	GiaSuc(){
		san_luong_sua = 0;
	}
	GiaSuc(float san_luong_sua, int id) {
		this->san_luong_sua = san_luong_sua;
		this->id = id;
	}
	static int TongSanLuongSua(vector<GiaSuc*> vt) {
		int tong = 0;
		for (auto x : vt)
		{
			tong += x->san_luong_sua;
		}
		return tong;
	}
	virtual void Keu() = 0;
	virtual void ChoSua() = 0;
	virtual GiaSuc* SinhCon() = 0;

};
class Bo : public GiaSuc {
private:
	static int so_luong;
public:
	Bo() {

		so_luong++;
	}

	void Keu() {
		cout << "um bo`,um bo`" << endl;
	}
	GiaSuc* SinhCon() {
		GiaSuc* temp = new Bo;
		return temp;
	}
	void ChoSua(){
		san_luong_sua = rand() % 21;
	}
};
int Bo::so_luong = 0;
class Cuu : public GiaSuc {
private:
	static int so_luong;
public:
	Cuu() {
		so_luong++;
	}

	void Keu() {
		cout << "be be" << endl;
	}
	GiaSuc* SinhCon() {
		GiaSuc* temp = new Cuu;
		return temp;
	}
	void ChoSua() {
		san_luong_sua = rand() % 6;
	}
};
int Cuu::so_luong = 0;
class De : public GiaSuc {
private:
	static int so_luong;
public:
	De() {
		so_luong++;
	}

	void Keu() {
		cout << "be be be" << endl;
	}
	GiaSuc* SinhCon() {
		GiaSuc* temp = new De;
		return temp;
	}
	void ChoSua() {
		san_luong_sua = rand() % 11;
	}
};
int De::so_luong = 0;

class TrangTrai {
private:
	vector<GiaSuc*> danh_sach_gia_suc;

public:
	TrangTrai() {}

	void ThemGiaSuc(GiaSuc* gia_suc) {
		danh_sach_gia_suc.push_back(gia_suc);
	}

	void KhiDoi() {
		for (auto gia_suc : danh_sach_gia_suc) {
			gia_suc->Keu();
		}
	}
	void SinhSan() {
		vector<GiaSuc*> dan_con;
		for (auto giasuc : danh_sach_gia_suc) {
			srand(time(NULL));
			int num  = rand() % 5; // moi con gia suc co the de tu 0 -> 5 con
			for (int i = 0; i < num; i++) {
				dan_con.push_back(giasuc->SinhCon());
			}
		}
		danh_sach_gia_suc.insert(danh_sach_gia_suc.end(), dan_con.begin(), dan_con.end());
	}
	void ThongKe() {
		int so_luong_bo = 0;
		int so_luong_cuu = 0;
		int so_luong_de = 0;
		int tong_san_luong_sua = 0;

		for (auto gia_suc : danh_sach_gia_suc) {
			if (dynamic_cast<Bo*>(gia_suc) != nullptr) {
				so_luong_bo++;
			}
			else if (dynamic_cast<Cuu*>(gia_suc) != nullptr) {
				so_luong_cuu++;
			}
			else if (dynamic_cast<De*>(gia_suc) != nullptr) {
				so_luong_de++;
			}
		}
		tong_san_luong_sua += GiaSuc::TongSanLuongSua(danh_sach_gia_suc);
		cout << "Thong ke:" << endl;
		cout << "So luong bo: " << so_luong_bo << endl;
		cout << "So luong cuu: " << so_luong_cuu << endl;
		cout << "So luong de: " << so_luong_de << endl;
		cout << "Tong san luong sua: " << tong_san_luong_sua << " (lit)" << endl;
	}
	void LaySua() {
		for (auto& giasuc : danh_sach_gia_suc) {
			giasuc->ChoSua();
		}
	}
	void NhapBanDau() {
		int so_luong_bo, so_luong_cuu, so_luong_de;

		cout << "Nhap so luong bo: ";
		cin >> so_luong_bo;
		cout << "Nhap so luong cuu: ";
		cin >> so_luong_cuu;
		cout << "Nhap so luong de: ";
		cin >> so_luong_de;

		for (int i = 0; i < so_luong_bo; i++) {
			Bo* temp = new Bo();
			ThemGiaSuc(temp);
		}
		for (int i = 0; i < so_luong_de; i++) {
			De* temp = new De();
			ThemGiaSuc(temp);
		}
		for (int i = 0; i < so_luong_cuu; i++) {
			Cuu* temp = new Cuu();
			ThemGiaSuc(temp);
		}
	}
};
int main() {
    TrangTrai trang_trai;
    trang_trai.NhapBanDau();

    cout << "a. Tieng keu nghe duoc trong nong trai khi doi:" << endl;
    trang_trai.KhiDoi();
	trang_trai.SinhSan();
	trang_trai.LaySua();
    cout << "b. Thong ke sau khi sinh con va cho sua:" << endl;
    trang_trai.ThongKe();
    return 0;
}
