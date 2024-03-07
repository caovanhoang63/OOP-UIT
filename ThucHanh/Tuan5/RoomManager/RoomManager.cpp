#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Phong {
public:
    string ten;
    int tang;
    int so_phong;
    int suc_chua;
    int id;
    virtual void Nhap() {
        cin.ignore();
        cin >> ten>>tang>>so_phong>>suc_chua;
    }
};
class PhongLyThuyet : public Phong {
public:
    int may_lanh;
    PhongLyThuyet() {
        id = 1;
    }
    void Nhap() {
        Phong::Nhap();
        cin >> may_lanh;
    }
};
class PhongThucHanh : public Phong {
public:
    int may_tinh;
    PhongThucHanh() {
        id = 2;
    }
    void Nhap() {
        Phong::Nhap();
        cin >> may_tinh;
    }
};
class GiangDuong : public Phong {
public:
    int may_chieu;
    GiangDuong() {
        id = 3;
    }
    void Nhap() {
        Phong::Nhap();
        cin >> may_chieu;
    }
};
class QuanLy {
public:
    vector<Phong*> danhsach;
    int suc_chua;
    int tong_suc_chua;
    QuanLy() {
        tong_suc_chua = 0;
    }
    void Nhap() {
        int n,id;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Phong* temp;
            cin >> id;
            switch (id)
            {
            case 1:
                temp = new PhongLyThuyet;
                break;
            case 2:
                temp = new PhongThucHanh;
                break;
            case 3:
                temp = new GiangDuong;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != nullptr) {
                temp->Nhap();
                tong_suc_chua += temp->suc_chua;
                danhsach.push_back(temp);
            }
        }
        cin >> suc_chua;
    }
    Phong* TimPhong() {
        Phong* result = NULL;
        for (Phong* x : danhsach) {
            if (x->suc_chua >= suc_chua) {
                if (result == NULL)
                    result = x;
                else if (x->so_phong < result->so_phong && x->tang < result->tang)
                    result = x;
            }
        }
        if (result !=NULL)
            return result;
        else
            return NULL;
    }
    void Xuat() {
        cout << tong_suc_chua << endl;
        Phong*  result= TimPhong();
        if (result == NULL)
            cout << "NULL" << endl;
        else
            cout << result->ten;
    }
};
int main() {
    QuanLy a;
    a.Nhap();
    a.Xuat();
    return 0;
}
