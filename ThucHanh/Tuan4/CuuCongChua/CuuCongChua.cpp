#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class HoangTu {
public:
    int so_tien;
    int tri_tue;
    int suc_manh;
    void Nhap() {
        cin >> so_tien >> tri_tue >> suc_manh;
    }
    void Xuat() {
        cout << so_tien << " " << tri_tue << " " << suc_manh;
    }
};
class Cong {
public:
    int loai;
    virtual void Nhap() = 0;
    virtual bool QuaCong(HoangTu * ) = 0;
};
class CongGiaoThuong :public Cong {
public:
    int don_gia;
    int so_hang;
    CongGiaoThuong() {
        loai = 1;
    }
    void Nhap() {
        cin >> don_gia >> so_hang;
    }
    bool QuaCong(HoangTu* hoang_tu) {
        if (hoang_tu->so_tien >= don_gia * so_hang) {
            hoang_tu->so_tien -= don_gia * so_hang;
            return 1;
        }
        return 0;
    }
};
class CongHocThuat : public Cong {
public:
    int tri_tue;
    CongHocThuat() {
        loai = 2;
    }
    void Nhap() {
        cin >> tri_tue;
    }
    bool QuaCong(HoangTu* hoang_tu) {
        if (hoang_tu->tri_tue >= this->tri_tue)
            return 1;
        return 0;
    }
};
class CongSucManh : public Cong {
public:
    int suc_manh;
    CongSucManh() {
        loai = 3;
    }
    void Nhap() {
        cin >> suc_manh;
    }
    bool QuaCong(HoangTu* hoang_tu) {
        if (hoang_tu->suc_manh >= this->suc_manh) {
            hoang_tu->suc_manh -= this->suc_manh;
            return 1;
        }
        return 0;
    }
};
class HanhTrinh {
public:
    HoangTu* hoang_tu;
    Cong** danh_sach;
    int so_luong_cong;
    HanhTrinh() {
        hoang_tu = new HoangTu;
    }
    void Nhap() {
        cin >> so_luong_cong;
        danh_sach = new Cong * [so_luong_cong];
        for (int i = 0; i < so_luong_cong; i++) {
            int loai;
            Cong* temp;
            cin >> loai;
            switch (loai)
            {
            case 1:
                temp = new CongGiaoThuong;
                break;
            case 2 :
                temp = new CongHocThuat;
                break;
            case 3:
                temp = new CongSucManh;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL)
                temp->Nhap();
            danh_sach[i] = temp;
        }
        hoang_tu->Nhap();
    }
    bool GiaiCuu() {
        for (int i = 0; i < so_luong_cong; i++) {
            if (!danh_sach[i]->QuaCong(hoang_tu))
                return 0;
        }
        return 1;
    }
    void KetQua() {
        if (GiaiCuu())
            hoang_tu->Xuat();
        else
            cout << -1;
    }
};
int main() {
    HanhTrinh a;
    a.Nhap();
    a.KetQua();
    return 0;
}
