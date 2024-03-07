#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
enum LoaiNguon {
	THUYDIEN = 1,
	NHIETDIEN,
	DIENGIO,
	DIENMATTROI
};
class ThoiTiet {
public:
	bool coMay;
	int tocdoGio;
	int gioHienTai;
	void Nhap() {
		cin >> gioHienTai >> tocdoGio >> coMay;
	}
};
class NguonDien {
public:
	LoaiNguon loai;
	float HieuSuat;
	float CongSuatToiDa;
	virtual void Nhap() {
		cin >> HieuSuat;
	}
	virtual float tinhHieuSuat(ThoiTiet,int) = 0;
	virtual void TinhCongSuatToiDa() = 0;
};
class ThuyDien : public NguonDien {
public:
	ThuyDien() {
		loai = THUYDIEN;
		tongTichNang = 0;
	}
	int soToMay;
	bool TichNang;
	float tongTichNang;
	void TinhCongSuatToiDa() {
		CongSuatToiDa = HieuSuat * soToMay;
	}
	void Nhap() {
		NguonDien::Nhap();
		
		cin >> soToMay >> TichNang;
	}
	float tinhHieuSuat(ThoiTiet thoitiet, int CongSuat) {
		return 1;
	}
	int TichDien(int DienDu) {
		int CoTheThem = CongSuatToiDa - tongTichNang;
		if (CoTheThem > 0)
		{
			if (DienDu >= CoTheThem) {
				tongTichNang+= CoTheThem;
				return DienDu - CoTheThem;
			}
			else {
				tongTichNang += DienDu;
				return 0;
			}
		}
		else {
			return DienDu;
		}
	}
};
class NhietDien : public NguonDien {
public:
	NhietDien() {
		loai = NHIETDIEN;
	}
	float luongThan;
	void Nhap() {
		NguonDien::Nhap();
		cin >> luongThan;
	}
	void TinhCongSuatToiDa() {
		CongSuatToiDa = HieuSuat * luongThan;
	}
	float tinhHieuSuat(ThoiTiet thoitiet, int CongSuat) {
		return 1;
	}
};
class DienGio : public NguonDien {
public:
	DienGio() {
		loai = DIENGIO;
	}

	int tuabin;
	float maxSpeed;
	void Nhap() {
		NguonDien::Nhap();
		cin >> tuabin>>maxSpeed;
	}
	void TinhCongSuatToiDa() {
		CongSuatToiDa = HieuSuat * tuabin;
	}
	float tinhHieuSuat(ThoiTiet thoithiet, int CongSuat) {
		return (thoithiet.tocdoGio / maxSpeed);
	}
};
class DienMatTroi : public NguonDien {
public:
	DienMatTroi() {
		loai = DIENMATTROI;
	}
	float dientich;
	void Nhap() {
		NguonDien::Nhap();
		cin >> dientich;
	}
	void TinhCongSuatToiDa() {
		CongSuatToiDa = HieuSuat * dientich;
	}
	float tinhHieuSuat(ThoiTiet thoitiet, int CongSuat) {
		int gio = thoitiet.gioHienTai;
		if (thoitiet.coMay || (gio >=18 && gio <=6) )
			return 0;
		if (gio >= 11 && gio <= 13)
			return 1;
		if (gio >= 6) {
			return 0.2 * (gio - 6);
		}
		return 1 - 0.2 * (gio - 13);
	}
};
class QuanLy {
public:
	vector<NguonDien*> danhsachNguon;
	vector<ThoiTiet> thoitiet;
	vector<int>CongSuat;
	long long tongThu;
	int thoigianra;
	void Nhap() {
		int soNguon,soGio,loai,congsuat;
		cin >> soNguon;
		danhsachNguon.resize(soNguon);
		for(NguonDien*&  nguon : danhsachNguon)
		{
			cin >> loai;
			switch (loai)
			{
			case THUYDIEN:
				nguon = new ThuyDien;
				break;
			case NHIETDIEN:
				nguon = new NhietDien;
				break;
			case DIENGIO:
				nguon = new DienGio;
				break;
			case DIENMATTROI:
				nguon = new DienMatTroi;
				break;
			default:
				nguon = NULL;
				break;
			}
			if (nguon != NULL) {
				nguon->Nhap();
				nguon->TinhCongSuatToiDa();
			}
		}
		cin >> soGio;
		thoitiet.resize(soGio);
		for (ThoiTiet& x : thoitiet) {
			x.Nhap();
			cin >> congsuat;
			CongSuat.push_back(congsuat);
		}
	}
	void HoatDong() {
		tongThu = 0;
		thoigianra = 0;

		int TongCongSuatHienTai = 0, TongCongSuatTruoc = 0;
		for (int i = 0; i < thoitiet.size(); i++) {
			TongCongSuatTruoc = TongCongSuatHienTai;
			TongCongSuatHienTai = 0;

			for (auto x : danhsachNguon) {
				if(thoigianra > 0 )
				{
					if (x->loai  == 2 || x->loai == 1)
						TongCongSuatHienTai += round(x->tinhHieuSuat(thoitiet[i], CongSuat[i]) * x->CongSuatToiDa);
				}
				else if(thoigianra <=0)
					TongCongSuatHienTai += round(x->tinhHieuSuat(thoitiet[i], CongSuat[i]) * x->CongSuatToiDa);
			}
			if (TongCongSuatHienTai > CongSuat[i]) {
				int DienNangDu = TongCongSuatHienTai - CongSuat[i];
				for (auto &x : danhsachNguon) {
					if (x->loai == 1) {
						ThuyDien* thuydien = dynamic_cast<ThuyDien*> (x);
						if (thuydien->TichNang)
							DienNangDu = thuydien->TichDien(DienNangDu);
					}
					if (DienNangDu == 0)
						break;
				}
			}
			int vuacong = 0;
			if (i != 0) {
				int chenhlech = abs(TongCongSuatTruoc - TongCongSuatHienTai);
				if ((float)chenhlech / TongCongSuatHienTai >= 0.2 || (float)chenhlech / TongCongSuatTruoc >= 0.2)
					thoigianra += 2;
				vuacong = 1;
			}
			float ti_le_dap_ung = TongCongSuatHienTai / CongSuat[i];
			if (ti_le_dap_ung < 1) {
				for (auto& x : danhsachNguon) {
					if (x->loai == 1) {
						ThuyDien* thuydien = dynamic_cast<ThuyDien*> (x);
						if (thuydien->TichNang) {
							TongCongSuatHienTai += thuydien->tongTichNang;
						}
					}
				}
			}
			ti_le_dap_ung = TongCongSuatHienTai / CongSuat[i];
			if (ti_le_dap_ung >= 1)
				tongThu += CongSuat[i] * 3000*1000;
			else if (ti_le_dap_ung >= 0.8)
				tongThu += TongCongSuatHienTai * 2500*1000;
			else
				tongThu += TongCongSuatHienTai * 2000*1000;
			if (thoigianra > 0 && vuacong == 0) {
				thoigianra--;
			}
			if (thoigianra > 2 && vuacong == 1) {
				thoigianra--;
			}
		}
	}
	void KetQua() {
		cout << tongThu;
	}
};
int main() {
	QuanLy a;
	a.Nhap();
	a.HoatDong();
	a.KetQua();
	return 0;
}