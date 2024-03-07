#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

class VatPham {
protected:
	string ten;
	float gia;
	string nsx;
	int loai;
public:
	virtual float GiaTriThuc() {
		return gia;
	}
	virtual void Nhap() = 0;
	string getTen(){
		return ten;
	}
	float getGia() {
		return gia;
	}
	string getNSX() {
		return nsx;
	}
	int getLoai() {
		return loai;
	}
	void setTen(string ten){
		this->ten = ten;
	}
	void setGia(float gia){
		this->gia = gia;
	}
	void setNSX(string nsx){ 
		this->nsx = nsx;
	}
	void setLoai(int loai){
		this->loai = loai;
	}
	friend class Sora;
};
class Quan :public VatPham {
protected:
	float chieu_dai;
public:
	void Nhap() {
		cin >> ten;
		cin >> gia;
		cin >> nsx;
		cin >> chieu_dai;
	}
};
class QuanKaki : public Quan {
public:
	QuanKaki() {
		loai = 1;
	}
	float GiaTriThuc() {
		return gia * 0.8;
	}
};
class QuanJean : public Quan {
public:
	QuanJean() {
		loai = 2;
	}
	float GiaTriThuc() {
		return gia * 1.5;
	}
};
class Ao :public VatPham {
protected:
	string mausac;
public:
	void Nhap() {
		cin >> ten;
		cin >> gia;
		cin >> nsx;
		cin>>mausac;
	}
};
class AoNganTay : public Ao {
private:
	bool coCO;
public:
	void Nhap() {
		cin >> ten;
		cin >> gia;
		cin >> nsx;
		cin >> mausac;
		cin >> coCO;
	}
	AoNganTay() {
		loai = 3;
	}
};
class AoDaiTay : public Ao {
private:
	float chieu_dai_ong_tay;
public:
	AoDaiTay() {
		loai = 4;
	}
	void Nhap() {
		cin >> ten;
		cin >> gia;
		cin >> nsx;
		cin >> mausac;
		cin >> chieu_dai_ong_tay;
	}
};
class Mu : public VatPham {
protected:
	int level;
public:
	void Nhap() {
		cin >> ten;
		cin >> gia;
		cin >> nsx;
		cin >> level;
	}
};
class MuSat : public Mu {
public:
	MuSat() {
		loai = 5;
	}
	float GiaTriThuc() {
		return 0;
	}
};
class MuBac : public Mu {
public:
	MuBac() {
		loai = 6;
	}
};
class MuVang : public Mu {
public:
	MuVang() {
		loai = 7;
	}

};
class Sora {
private:
	vector<VatPham*> list;
public:
	Sora() {}
	void NhapDanhSachDo() {
		int so_luong;
		cin >> so_luong;
		for (int i = 0; i < so_luong; i++) {
			VatPham* vatpham ;
			int loai;
			cin >> loai;
			switch (loai)
			{
			case 1:
				vatpham = new QuanKaki;
				break;
			case 2:
				vatpham = new QuanJean;
				break;
			case 3:
				vatpham = new AoDaiTay;
				break;
			case 4:
				vatpham = new AoNganTay;
				break;
			case 5:
				vatpham = new MuSat;
				break;
			case 6:
				vatpham = new MuBac;
				break;
			case 7:
				vatpham = new MuVang;
				break;
			default:
				vatpham = NULL;
				break;
			}
			if (vatpham != NULL) {
				vatpham->Nhap();
				list.push_back(vatpham);
			}
		}
	}
	float TinhBuff() {
		float max_buff = 0;
		for (auto x : list) {
			float temp = 0;
			switch (x->loai)
			{
			case 6:
				temp = 1.5;
				break;
			case 7:
				temp = 3;
				break;
			default:
				temp = 1;
			}
			if (temp > max_buff)
				max_buff = temp;
		}
		return max_buff;
	}
	float TongGiaTri() {
		float sum = 0;
		float buff = TinhBuff();
		for (auto x : list) {
			if (x->loai >= 5 && x->loai <= 7) {
				sum += x->GiaTriThuc();
			}
			else
			{
				sum += x->GiaTriThuc() *buff;
			}
		}
		return sum;
	}
};
int main() {
	Sora sora;
	sora.NhapDanhSachDo();
	cout << sora.TongGiaTri();
	return 0;
}