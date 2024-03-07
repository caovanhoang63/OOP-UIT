#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
enum Loai {
    GIAMDOC = 1,
    DAILY ,
    NDT
};
class GoiDauTu {
public:
    
    int loai;
    float lai;
    int gia;
    int TraLai() {
        return lai * gia;
    }
};
class GoiBac : public GoiDauTu{
public:
    GoiBac() {
        loai = 1;
        lai = 0.1;
    }
};
class GoiVang : public GoiDauTu {
public:
    GoiVang() {
        loai = 2;
        lai = 0.12;
    }
};
class GoiKimCuong : public GoiDauTu {
public:
    GoiKimCuong() {
        loai = 3;
        lai = 0.15;
    }
};
class ThanhVien {
public:
    vector<GoiDauTu* > goidautu;
    Loai loai;
    int id;
    string ten;
    int so_du;
    ThanhVien() {
        so_du = 0;
    }
    virtual void Nhap() {
        cin >> ten;
    }
    void Xuat() {
        cout << id << " " << so_du << endl;
    }
    void NhanTien(int so_tien) {
        so_du += so_tien;
    }
    void ChiTien(int so_tien) {
        so_du -= so_tien;
    }
    GoiDauTu* MuaGoi(int so_tien) {
        if (so_tien <= 0)
            return NULL;
        GoiDauTu* temp =  NULL;
        if (so_tien >= 1 && so_tien <= 100) {
            temp = new GoiBac;
        }
        else if (so_tien >= 101 && so_tien <= 200) {
            temp = new GoiVang;
        }
        else if (so_tien >= 201)
            temp = new GoiKimCuong;
        if (temp != NULL)
        {
            temp->gia = so_tien;
            goidautu.push_back(temp);
            return temp;
        }
        return NULL;
    }
};
class GiamDoc : public ThanhVien {
public:
    GiamDoc() {
        so_du = 0;
        loai = GIAMDOC;
    }
    void NhanTien(int so_tien) {
        so_du += so_tien;
    }

};
class DaiLy : public ThanhVien {
public:
    int id_DaiLy;
    int cap;
    int tong_gop;
    DaiLy() {
        loai = DAILY;
        so_du = 0;
        tong_gop = 0;
        id_DaiLy = NAN;
        cap = 0;
    }
    int  NhanHoaHong(int so_tien) {
        int hoa_hong = so_tien * (((float)5 + cap * 3) / 100);
        so_du += hoa_hong;
        return hoa_hong;
    }
    void Nhap() {
        ThanhVien::Nhap();
        cin >> cap;
    }
    void ThangCap() {
        cap++;
    }
};
class NhaDauTu : public ThanhVien {
public:
    int id_DaiLy;
    NhaDauTu() {
        loai = NDT;
        so_du = 0;
    }
    void Nhap() {
        ThanhVien::Nhap();
        cin >> id_DaiLy;
    }
    int TongDauTu() {
        int tong = 0;
        for (auto x : goidautu) {
            tong += x->gia;
        }
        return tong;
    }
    ThanhVien* ThangCap() {
            ThanhVien* temp = new DaiLy;
            *temp = *this;
            temp->so_du += 100;
            return temp;
    }
};
class CongTy {
public:
    ThanhVien* GD;
    vector<ThanhVien*> danhsachThanhVien;
    int so_thang;
    void Nhap() {
        int n, loai,id;
        cin >> n >> so_thang;
        danhsachThanhVien.resize(n);
        for (ThanhVien*& x : danhsachThanhVien) {
            cin >> id;
            cin >> loai;
            switch (loai)
            {
            case 1:
                x = new GiamDoc;
                GD = x;
                break;
            case 2:
                x = new DaiLy;
                break;
            case 3:
                x = new NhaDauTu;
                break;
            default:
                break;
            }
            x->id = id;
            x->Nhap();
        }
    }
    void HoatDong() {
        int n,id;
        if (danhsachThanhVien.empty())
            return;
        for (int i = 1; i <= so_thang; i++) {
            for (ThanhVien*& x : danhsachThanhVien) {
                int tong = 0;
                for (GoiDauTu*& goi : x->goidautu) {
                    tong += goi->TraLai();
                    x->NhanTien(goi->TraLai());
                }
                GD->ChiTien(tong);
            }
            for(int  j = 1 ; j <= danhsachThanhVien.size() - 1 ; j++)
            {
                cin >> id >> n;
                for (ThanhVien*& x : danhsachThanhVien) {
                    if (x->id == id) {
                        MuaGoi(x, n);
                    }
                }
            }
        }
    }
    void MuaGoi(ThanhVien*& thanhvien, int so_tien) {
        GoiDauTu* goidautu = thanhvien->MuaGoi(so_tien);
        if(goidautu !=NULL)
        {
            if (thanhvien->loai == 3) {
                NhaDauTu* a = dynamic_cast<NhaDauTu*>(thanhvien);
                for (ThanhVien*& x : danhsachThanhVien) {
                    if (x->id == a->id_DaiLy) {
                        DaiLy* daily = dynamic_cast<DaiLy*>(x);
                        int hoahong = daily->NhanHoaHong(goidautu->gia);
                        GD->NhanTien(goidautu->gia - hoahong);
                    }
                }
            }
            else if (thanhvien->loai == 2) {
                GD->NhanTien(goidautu->gia);
            }
        }
    }
    void KetQua() {
        if (danhsachThanhVien.empty()) {
            return;
        }
        for (ThanhVien* x : danhsachThanhVien) {
            x->Xuat();
        }
    }
};
int main() {
    CongTy UIT;
    UIT.Nhap();
    UIT.HoatDong();
    UIT.KetQua();
    return 0;
}
