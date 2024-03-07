#include <iostream>
#include <string>
#include <iomanip>
#include "class.cpp"
#include <vector>


using namespace std;

int main() {
	vector<Human*> danhSach;
	int loaiDoiTuong;
	do {
		cout << "Chon loai doi tuong (1: Sinh vien, 2: Hoc sinh, 3: Cong nhan, 4: Nghe si, 5: Ca si, 0: Ket thuc): ";
		cin >> loaiDoiTuong;
		cin.ignore();
		switch (loaiDoiTuong) {
		case 1: {
			Student* st = new Student();
			st->Enter();
			danhSach.push_back(st);
			break;
		}
		case 2: {
			Pupil* pu = new Pupil();
			pu->Enter();
			danhSach.push_back(pu);
			break;
		}
		case 3: {
			Worker* w = new Worker();
			w->Enter();
			danhSach.push_back(w);
			break;
		}
		case 4: {
			Artist* a = new Artist();
			a->Enter();
			danhSach.push_back(a);
			break;
		}
		case 5: {
			Singer* s = new Singer();
			s->Enter();
			danhSach.push_back(s);
			break;
		}
		default:
			break;
		}
	} while (loaiDoiTuong != 0);
	system("cls");
	cout << "Danh sach doi tuong: " << endl;
	for (auto x : danhSach)
	{
		x->Print();
	}
	//Student* p = (Student*)&(danhSach[0]);
	for (int i = 0; i < danhSach.size(); i++) {
		delete danhSach[i];
	}

	return 0;
}

