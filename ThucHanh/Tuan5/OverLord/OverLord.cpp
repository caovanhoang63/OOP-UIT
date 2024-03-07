#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<string>
#include <algorithm>
using namespace std;
enum Type { HUMAN = 1, ELF, ORC, GOLBIN, VAMPIRE, DEVIL, BOSS };
class NhanVat {
public:
	string ten;
	float hp;
	float atk;
	float def;
	Type loai;
	virtual void Nhap() {
		cin >> ten >> hp >> atk >> def;
	}
	void Xuat() {
		cout << ten << " " << hp << endl;
	}
	void TanCong(NhanVat*& temp) {
		if (this->hp <= 0 || this->atk < temp->def)
			return;
		temp->hp -= this->atk - temp->def;
	}
	virtual void Buff() = 0;
	virtual void Buff(vector<NhanVat*>) = 0;
};
class NhanLoai : public  NhanVat {
public:
	string job_class;
	void Nhap() {
		NhanVat::Nhap();
		cin >> job_class;
	}
	void Buff(vector<NhanVat*>) {
		return;
	}

};
class BanNhan : public NhanVat {
public:
	string racial_class;
	void Nhap() {
		NhanVat::Nhap();
		cin >> racial_class;
	}
	void Buff(vector<NhanVat*>) {
		return;
	}
};
class DiHinh : public NhanVat {
public:
	void Buff() {
		return;
	}
};
class Human : public NhanLoai {
public:
	Human() {
		loai = HUMAN;
	}
	void Buff() {
		return;
	}
};
class Elf : public NhanLoai {
public:
	Elf() {
		loai = ELF;
	}
	void Buff() {
		def *= 1.5;
	}
};
class Orc : public BanNhan {
public:
	Orc() {
		loai = ORC;
	}
	void Buff() {
		hp *= 1.5;
	}
};
class Golbin : public BanNhan {
public:
	Golbin() {
		loai = GOLBIN;
	}
	void Buff() {
		atk *= 1.1;
	}
};
class Vampire : public DiHinh {
public:
	Vampire() {
		loai = VAMPIRE;
	}
	void Buff(vector<NhanVat*> vt) {
		float trong_so = 1;
		for (NhanVat* x : vt) {
			if (x->loai == HUMAN || x->loai == ELF)
				trong_so += 0.1;
		}
		this->hp *= trong_so;
	}
};
class Devil : public DiHinh {
public:
	Devil() {
		loai = DEVIL;
	}
	void Buff(vector<NhanVat*> vt) {
		float trong_so = 1;
		for (NhanVat* x : vt) {
			if (x->loai == DEVIL)
				trong_so += 0.1;
		}
		this->atk *= trong_so;
		this->def *= trong_so;
	}
};
class Boss : public NhanVat {
public:
	Boss() {
		loai = BOSS;
	}
	void Buff() {
		return;
	}
	void Buff(vector<NhanVat*>) {
		return;
	}
	NhanVat* ChonMucTieu(vector<NhanVat*> vt) {
		NhanVat* result = NULL;
		for (auto x : vt) {
			if (x->hp > 0) {
				if (result == NULL)
					result = x;
				else if (result->hp > x->hp)
					result = x;
			}
		}
		return result;
	}
};
class Guild {
public:
	vector<NhanVat*>danhsach;
	void Nhap() {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int loai;
			NhanVat* temp = NULL;
			cin >> loai;
			switch (loai)
			{
			case HUMAN:
				temp = new Human;
				break;
			case ELF:
				temp = new Elf;
				break;
			case ORC:
				temp = new Orc;
				break;
			case GOLBIN:
				temp = new Golbin;
				break;
			case VAMPIRE:
				temp = new Vampire;
				break;
			case DEVIL:
				temp = new Devil;
				break;
			default:
				NULL;
				break;
			}
			if (temp != NULL) {
				temp->Nhap();
				danhsach.push_back(temp);
			}
		}
	}
	void Buff() {
		for (auto& x : danhsach) {
			x->Buff();
			x->Buff(danhsach);
		}
	}
};
bool compare(NhanVat* a, NhanVat* b)
{
	return a->hp < b->hp;
}
class PhieuLuu {
public:
	Guild guild;
	Boss* boss;
	void Nhap() {
		guild.Nhap();
		guild.Buff();
		boss = new Boss;
		boss->Nhap();
	}
	bool GiaoTranh() {
		NhanVat* _boss = boss;
		int i = 1;
		while (boss->hp > 0 && boss->ChonMucTieu(guild.danhsach) != NULL && i <= 100) {
			for (auto x : guild.danhsach) {
				x->TanCong(_boss);
			}
			NhanVat* temp = boss->ChonMucTieu(guild.danhsach);
			boss->TanCong(temp);
			i++;
		}
		if (boss->hp <= 0)
			return true;
		return false;
	}

	void Xuat() {
		if (GiaoTranh()) {
			sort(guild.danhsach.begin(), guild.danhsach.end(), compare);
			for (auto x : guild.danhsach) {
				if (x->hp > 0)
					x->Xuat();
			}
		}
		else {
			boss->Xuat();
		}
	}
};
int main() {
	PhieuLuu a;
	a.Nhap();
	a.Xuat();
	return 0;
}