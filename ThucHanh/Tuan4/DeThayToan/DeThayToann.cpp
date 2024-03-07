#include <iostream>
#include <string>
#include <vector>
using namespace std;
enum CPU_Type {alpha = 1,beta = 2, gamma = 3};
class CPU {
public:
	string ma;
	CPU_Type loai;
	string hang;
	int so_core;
	float clock;
	int gia;
	CPU(CPU_Type loai, string hang, int so_core,float clock,int gia)
	: loai(loai),hang(hang),so_core(so_core),clock(clock),gia(gia) {}
	void Nhap() {
		cin.ignore();
		cin >> ma;
	}
	friend ostream& operator<<(ostream& os, CPU temp){
		string Loai;
		switch (temp.loai)
		{
		case alpha:
			Loai = "Alpha";
			break;
		case beta:
			Loai = "Beta";
			break;
		case gamma:
			Loai = "Gamma";
			break;
		default:
			break;
		}
		os << "CPU: " << temp.ma << " " << Loai << " " << temp.hang << " " << temp.so_core << " " << temp.clock << " " << temp.gia << endl;
		return os;
	}
};
class CPU_Alpha : public CPU{
public:
	CPU_Alpha()
		:CPU(alpha, "Black", 2, 1.8, 200) {}
};
class CPU_Beta : public CPU {
public:
	CPU_Beta()
		:CPU(beta, "Black", 2, 1.8, 200) {}
};
class CPU_Gamma : public CPU {
public:
	CPU_Gamma()
		:CPU(gamma, "Black", 2, 1.8, 200) {}
};
enum LoaiManHinh {HD =  1, FullHD};
class ManHinh {
public:
	string ma;
	string hang;
	LoaiManHinh loai;
	int gia;
	ManHinh(string ma, string hang){
		this->ma = ma;
		this->hang = hang;
	}
	ManHinh(string ma,string hang,LoaiManHinh loai,int gia)
	: ma(ma), hang(hang),loai(loai),gia(gia) {}
	virtual string Xuat(){
		string Loai;
		switch (this->loai)
		{
		case HD:
			Loai = "HD";
			break;
		case FullHD:
			Loai = "FullHD";
			break;
		default:
			break;
		}
		string result = "Man hinh: "+ ma +" "+ hang +" " + Loai +" "+  to_string(gia) +" ";
		return result;
	}
	virtual void Nhap() {
		cin.ignore();
		cin >> ma;
		cin.ignore();
		cin >> hang;
		cin >> gia;
	}
};
class ManHinhHD : public ManHinh {
public:
	ManHinhHD(string ma,string hang)
		: ManHinh(ma,hang){
		gia = 200;
		loai = HD;
	}

};
class ManHinhFuLLHD: public ManHinh{
public:
	bool chong_loa;
	ManHinhFuLLHD(string ma, string hang,bool chong_loa) 
	: ManHinh(ma,hang){
		this->chong_loa = chong_loa;
		gia = chong_loa ? 500 : 300;
	}
	void Nhap() {
		ManHinh::Nhap();
		cin >> chong_loa;
		gia = chong_loa ? 500 : 300;
	}
	string Xuat() {
		string result = ManHinh::Xuat() + to_string(chong_loa);
		return result;
	}
	
};
enum LoaiVo {nhom =1 ,nhua};
class Vo {
public:
	string ma;
	LoaiVo loai;
	string hang;
	int gia;
	int mau;
	Vo() {
	}
	void Nhap() {
		cin.ignore();
		cin >> ma;
		cin >> mau;
	}
	void Xuat() {
		string Loai,Mau;
		switch (loai)
		{
		case nhom:
			Loai = "Nhom";
			break;
		case nhua:
			Loai = "Nhua";
			break;
		default:
			break;
		}
		switch (mau)
		{
		case 1:
			Mau = "Do";
			break;
		case 2:
			Mau = "Den";
			break;
		case 3:
			Mau = "Xanh";
			break;
		default:
			break;
		}
		cout << "Vo smartphone: " << ma<< " " << Loai << " " << hang << " " <<Mau << " " << gia<< endl;
	}
};
class VoNhom : public Vo{
public:
	VoNhom() {
		loai = nhom;
		hang = "Black";
		gia = 400;
	}
};
class VoNhua : public Vo{
public:
	VoNhua() {
		loai = nhua;
		hang = "White";
		gia = 200;
	}
};
enum LoaiDienThoai { venus = 1,mars,jupiter};
class DienThoai {
public:
	string ma;
	ManHinh* manhinh;
	Vo* vo;
	CPU* cpu;
	int gia;
	LoaiDienThoai loai;
	void Nhap() {
		cin.ignore();
		cin >> ma;
		int loai_cpu,loai_manhinh,loai_vo;
		cin >> loai_cpu;
		switch (loai_cpu)
		{
		case 1: 
			cpu = new CPU_Alpha;
			break;
		case 2:
			cpu = new CPU_Beta;
			break;
		case 3:
			cpu = new CPU_Gamma;
			break;
		default:
			break;
		}
		cpu->Nhap();
		
		/****************/
		string HangManHinh, MaManHinh;
		cin.ignore();
		cin >> MaManHinh;
		cin >> HangManHinh;
		cin >> loai_manhinh;
		switch (loai_manhinh)
		{
		case 1:
			manhinh = new ManHinhHD(MaManHinh, HangManHinh);
			break;
		case 2: {
			bool chong_loa;
			cin >> chong_loa;
			manhinh = new ManHinhFuLLHD(MaManHinh, HangManHinh, chong_loa);
			break;
		}
		default:
			break;
		}
		/****************/
		cin >> loai_vo;
		switch (loai_vo)
		{
		case 1:
			vo = new VoNhom;
			break;
		case 2:
			vo = new VoNhua;
			break;
		default:
			break;
		}
		vo->Nhap();
	}
	void Xuat() {
		string Loai;
		switch (loai)
		{
		case venus:
			Loai = "Venus";
			break;
		case mars:
			Loai = "Mars";
			break;
		case jupiter:
			Loai = "Jupiter";
			break;
		default:
			break;
		}
		cout << "Smartphone: " << ma << " " << Loai << " " << gia << endl;
		cout << *cpu;
		cout<<manhinh->Xuat()<<endl;
		vo->Xuat();
	}
	virtual void TinhGia() = 0;
};
class DienThoaiVenus :public DienThoai {
public:
	DienThoaiVenus() {
		loai = venus;
	}
	void TinhGia() {
		gia = 1.3 * (vo->gia + manhinh->gia + cpu->gia);
	}
};
class DienThoaiMars : public DienThoai {
public:
	DienThoaiMars() {
		loai = mars;
	}
	void TinhGia() {
		gia = 1.5 * (vo->gia + manhinh->gia + cpu->gia);
	}
};
class DienThoaiJupiter : public DienThoai {
public:
	DienThoaiJupiter() {
		loai = jupiter;
	}
	void TinhGia() {
		gia = 1.8 * (vo->gia + manhinh->gia + cpu->gia);
	}
};
int main() {
	vector<DienThoai* >danhsach;
	int n;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		DienThoai* temp;
		int LoaiDienThoai;
		cin >> LoaiDienThoai;
		switch (LoaiDienThoai)
		{
		case 1:
			temp = new DienThoaiVenus;
			break;
		case 2:
			temp = new DienThoaiMars;
			break;
		case 3:
			temp = new DienThoaiJupiter;
			break;
		default:
			temp = NULL;
			break;
		}
		temp->Nhap();
		temp->TinhGia();
		danhsach.push_back(temp);
	}
	for (auto x : danhsach) {
		x->Xuat();
	}
	return 0;
}