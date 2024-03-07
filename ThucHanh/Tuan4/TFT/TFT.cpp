#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
enum Loai { shaco = 1, zed = 2 };
class Tuong {
public:
    string ten;
    int tan_cong;
    Loai loai;
    int cap;
    Tuong() {
        cap = 1;
    }
    virtual int TanCong(int n) = 0;
    void Nhap() {
        cin >> tan_cong;
    }
    void Xuat(int n) {
        cout << ten << " - " << TanCong(n) << endl;
    }
    void TangCap(Tuong* tuong1, Tuong* tuong2) {
        this->cap++;
        this->tan_cong = (this->tan_cong + tuong1->tan_cong + tuong2->tan_cong) * cap;
        delete tuong1;
        delete tuong2;
    }
};
class Zed : public Tuong {
public:
    static int so_cap1;
    static int so_cap2;
    static int so_cap3;
    Zed() {
        ten = "Zed";
        so_cap1++;
        loai = zed;
    }
    int TanCong(int n) {
        int tong = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0)
                tong += 3 * tan_cong;
            else
                tong += tan_cong;
        }
        return tong;
    }
};
int Zed::so_cap1 = 0;
int Zed::so_cap2 = 0;
int Zed::so_cap3 = 0;
class Shaco :public Tuong {
public:
    static int so_cap1;
    static int so_cap2;
    static int so_cap3;
    Shaco() {
        ten = "Shaco";
        so_cap1++;
        loai = shaco;
    }
    int TanCong(int n) {
        int tong = 0;
        for (int i = 1; i <= n; i++) {
            tong += 2 * tan_cong;
        }
        return tong;
    }
};
int Shaco::so_cap1 = 0;
int Shaco::so_cap2 = 0;
int Shaco::so_cap3 = 0;
class DauTruong {
public:
    vector<Tuong*> danhsach;
    int luot;
    void Nhap() {
        int n;
        cin >> n >> luot;
        for (int i = 0; i < n; i++) {
            Tuong* temp;
            int loai;
            cin >> loai;
            switch (loai)
            {
            case 1:
                temp = new Shaco;
                break;
            case 2:
                temp = new Zed;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                int count = 0;
                if (Shaco::so_cap1 == 3 || Zed::so_cap1 == 3) {
                    for (int i = 0; i < danhsach.size(); i++) {
                        if (danhsach[i]->loai == temp->loai && danhsach[i]->cap == 1) {
                            count = i;
                            for (int j = i + 1; j < danhsach.size(); j++) {
                                if (danhsach[j]->loai == temp->loai && danhsach[j]->cap == 1) {
                                    danhsach[i]->TangCap(temp, danhsach[j]);
                                    danhsach.erase(danhsach.begin() + j);
                                    if (danhsach[i]->loai == shaco)
                                    {
                                        Shaco::so_cap2++;
                                        Shaco::so_cap1 -= 3;
                                    }
                                    else {
                                        Zed::so_cap1 -= 3;
                                        Zed::so_cap2++;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    if (Shaco::so_cap2 == 3 || Zed::so_cap2 == 3) {
                        for (int i = 0; i < danhsach.size(); i++) {
                            if (danhsach[i]->loai == danhsach[count]->loai && danhsach[i]->cap == 2) {
                                for (int j = i + 1; j < danhsach.size(); j++) {
                                    if (danhsach[j]->loai == danhsach[count]->loai && danhsach[j]->cap == 2) {
                                        danhsach[i]->TangCap(danhsach[count], danhsach[j]);
                                        danhsach.erase(danhsach.begin() + count);
                                        danhsach.erase(danhsach.begin() + j);
                                        if (danhsach[i]->loai == shaco)
                                        {
                                            Shaco::so_cap3++;
                                            Shaco::so_cap2 -= 3;
                                        }
                                        else {
                                            Zed::so_cap2 -= 3;
                                            Zed::so_cap3++;
                                        }
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
                else {
                    danhsach.push_back(temp);
                }
            }
        }
    }
    void buff() {
        if ((Shaco::so_cap1 + Shaco::so_cap2 + Shaco::so_cap3) != 0 && (Zed::so_cap1 + Zed::so_cap2 + Zed::so_cap3) != 0) {
            for (auto x : danhsach) {
                x->tan_cong += 10;
            }
        }
    }
    void Xuat() {
        buff();
        for (auto x : danhsach) {
            x->Xuat(luot);
        }
    }
};
int main() {
    DauTruong a;
    a.Nhap();
    a.Xuat();
    return 0;
}