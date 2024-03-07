#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
class Ban {
public:
	Ban() {
		soBan++;
	}
	string ten;
	int tuoi;
	virtual void Nhap() {
		cin >> ten >> tuoi;
	}
	virtual float tinhThoiGian() = 0;
	virtual  void Xuat() {
		cout << "Ten: " << ten << ", tuoi: " << tuoi << ", ";
	}
	static int soBan;
};
int Ban::soBan = 0;
class BanThan : public Ban{
public:
	string so_dien_thoai;
	void Nhap() {
		Ban::Nhap();
		cin >> so_dien_thoai;
	}
	float tinhThoiGian() {
		return 5;
	}
	void Xuat() {
		Ban::Xuat();
		cout << "so dien thoai: " << so_dien_thoai << endl;
	}
};
class BanTrai: public Ban {
public:
	long long income;
	void Nhap() {
		Ban::Nhap();
		cin >> income;
	}
	float tinhThoiGian() {
		return 5 * income /10000000.0;
	}
	void Xuat() {
		Ban::Xuat();
		cout << "thu nhap: " <<income <<"d"<< endl;
	}
};
class BanTraiKhac: public Ban {
public:
	float do_hap_dan;
	void Nhap() {
		Ban::Nhap();
		cin >> do_hap_dan;
		cout << do_hap_dan << endl;
	}
	float tinhThoiGian() {
		return do_hap_dan * 20 / Ban::soBan;
	}
	void Xuat() {
		Ban::Xuat();
		string s;
		if (do_hap_dan >= 0.7)
			s = "cao";
		else if(do_hap_dan < 0.4) {
			s = "thap";
		}
		else {
			s = "trung binh";
		}
		cout << "do thu hut: " << s << endl;
	}
};

int main() {
	int n,loai;
	cin >> n;
	vector<Ban*> danhsach(n);
	for (Ban*& x : danhsach) {
		cin >> loai;
		switch (loai)
		{
		case 1:
			x = new BanThan;
			break;
		case 2:
			x = new BanTrai;
			break;
		case 3:
			x = new BanTraiKhac;
			break;
		default:
			x = NULL;
			break;
		}
		if (x != NULL) {
			x->Nhap();
		}
	}
	float banthan = 0, bantrai = 0, bantraikhac = 0;
	float max = 0;
	if(!danhsach.empty())
	{
		for (Ban* x : danhsach) {
			if (max < x->tinhThoiGian())
				max = x->tinhThoiGian();
			if (dynamic_cast<BanThan*> (x))
				banthan += x->tinhThoiGian();
			else if (dynamic_cast<BanTrai*> (x))
				bantrai += x->tinhThoiGian();
			else
				bantraikhac += x->tinhThoiGian();
		}
		cout << "Thong ke: " << endl;
		if(banthan > 0)
			cout << "-Thoi gian cho ban than: " << banthan << " h" << endl;
		if(bantrai>0)
			cout << "-Thoi gian cho ban trai: " << bantrai << " h" << endl;
		if(bantraikhac> 0)
			cout << "-Thoi gian cho ban trai khac: " << bantraikhac << " h" << endl;
		cout << "Nguoi ban quan trong nhat: " << endl;
		for (Ban* x : danhsach)
			if (x->tinhThoiGian() == max)
				x->Xuat();
	}
	return 0;
}