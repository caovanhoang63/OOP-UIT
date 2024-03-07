#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
enum Loai { bo = 1, cuu, de, tho };
class DongVat {
public:
    int luong_sua;
    Loai loai;
    int tuoi;
    DongVat() {
        tuoi = 999;
    }
    virtual void Keu() = 0;
    virtual DongVat* SinhCon() = 0;
    virtual void  ChoSua() = 0;

};
class Bo : public DongVat {
public:
    static int so_luong;
    static int tong_sua;
    Bo() {
        luong_sua = 10;
        loai = bo;
        so_luong++;
    }
    void Keu() {
        cout << "Booo";
    }
    DongVat* SinhCon() {
        DongVat* con = new Bo;
        con->tuoi = 0;
        return con;
    }
    void  ChoSua() {
        if (this->tuoi > 3)
            tong_sua += luong_sua;
        return;
    }

};
int Bo::so_luong = 0;
int Bo::tong_sua = 0;
class Cuu : public DongVat{
public:
    static int so_luong;
    static int tong_sua;
    Cuu() {
        loai = cuu;
        so_luong++;
        luong_sua = 5;
    }
    void Keu() {
        cout << "Beee";
    }
    DongVat* SinhCon() {
        DongVat* con = new Cuu;
        con->tuoi = 0;
        return con;
    }
    void  ChoSua() {
        if (this->tuoi >3)
            tong_sua += luong_sua;
        return;
    }

};
int Cuu::so_luong = 0;
int Cuu::tong_sua = 0;
class De : public DongVat {
public:
    static int so_luong;
    static int tong_sua;
    De() {
        loai = de;
        so_luong++;
        luong_sua = 8;
    }
    void Keu() {
        cout << "Eeee";
    }
    DongVat* SinhCon() {
        DongVat* con = new De;
        con->tuoi = 0;
        return con;
    }
    void  ChoSua() {
        if (this->tuoi > 3)
            tong_sua += luong_sua;
        return;
    }
};
int De::so_luong = 0;
int De::tong_sua = 0;
class Tho: public DongVat {
public:
    static int so_luong;
    static int tong_sua;
    Tho() {
        loai = tho;
        so_luong++;
        luong_sua = 0;
    }
    void Keu() {
        return;
    }
    DongVat* SinhCon() {
        DongVat* con = new Tho;
        con->tuoi = 0;
        return con;
    }
    void  ChoSua() {
        if (this->tuoi >= 3)
            tong_sua += luong_sua;
        return;
    }
};
int Tho::so_luong = 0;
int Tho::tong_sua = 0;
class TrangTrai {
public:
    vector<DongVat*> danhsach;
    int luot;
    TrangTrai() {}
    void Nhap() {
        int so_bo, so_cuu, so_de, so_tho;
        cin >> so_bo >> so_cuu >> so_de >> so_tho;
            ThemLoai(bo,so_bo);
            ThemLoai(cuu,so_cuu);
            ThemLoai(de,so_de);
            ThemLoai(tho,so_tho);
        cin >> luot;
    }
    void ThemDongVat(DongVat* temp) {
        danhsach.push_back(temp);
    }
    void ThemLoai(Loai loai, int n, int tuoi = 999) {
        for(int i = 0 ; i < n ; i ++)
        {
            DongVat* temp;
            switch (loai)
            {
            case bo:
                temp = new Bo;
                break;
            case cuu:
                temp = new Cuu;
                break;
            case de:
                temp = new De;
                break;
            case tho:
                temp = new Tho;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL)
            {
                temp->tuoi = tuoi ;
                danhsach.push_back(temp);
            }
        }
    }
    void SinhSan() {
        int so_bo = 0, so_cuu = 0, so_de = 0, so_tho = 0;
        for (auto x : danhsach) {
            if ((x->loai <= 3 && x->tuoi > 3)|| (x->loai ==4 && x->tuoi > 1)) {
                switch (x->loai)
                {
                case bo:
                    so_bo++;
                    break;
                case cuu:
                    so_cuu++;
                    break;
                case de:
                    so_de++;
                    break;
                case tho:
                    so_tho++;
                    break;
                default:
                    break;
                }
            }
        }
        ThemLoai(bo, so_bo/2,0);
        ThemLoai(cuu, so_cuu/2,0);
        ThemLoai(de, so_de/2,0);
        ThemLoai(tho, so_tho/2,0);
    }
    void LaySua() {
        for (DongVat* x : danhsach) {
            x->ChoSua();
        }
    }
    void HoatDong() {
        for(int i = 0 ; i < luot  ;i++)
        {
            for (DongVat*& x : danhsach) {
                x->tuoi++;
            }
            SinhSan();
            LaySua();
        }
    }
    void ThongKe() {
        cout << "Bo: " << Bo::so_luong <<","<<Bo::tong_sua << endl;
        cout << "Cuu: " << Cuu::so_luong << "," << Cuu::tong_sua << endl;
        cout << "De: " << De::so_luong << "," << De::tong_sua << endl;
        cout << "Tho: " << Tho::so_luong << "," << Tho::tong_sua << endl;
    }
};
int main() {
    TrangTrai a;
    a.Nhap();
    a.HoatDong();
    a.ThongKe();
    return 0;
}
