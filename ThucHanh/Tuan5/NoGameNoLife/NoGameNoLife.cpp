#include <vector>
#include <iostream>
#include <string>
using namespace std;
class VatPham {
public:
    string ten;
    float gia;
    string nsx;
    int loai;
    virtual float GiaTriThuc() {
        return gia;
    }
    virtual void Nhap() {
        cin >> ten >> gia >> nsx;
    }
    static float buff;
};
float VatPham::buff = 1;
class Quan :public VatPham {
public:
    float chieu_dai;
    void Nhap() {
        VatPham::Nhap();
        cin >> chieu_dai;
    }
};
class QuanKaki : public Quan {
public:
    QuanKaki() {
        loai = 1;
    }
    float GiaTriThuc() {
        gia = gia * 0.8;
        return gia;
    }
};
class QuanJean : public Quan {
public:
    QuanJean() {
        loai = 2;
    }
    float GiaTriThuc() {
        gia = gia * 1.5;
        return gia;
    }
};
class Ao :public VatPham {
public:
    string mausac;
    virtual void Nhap() {
        VatPham::Nhap();
        cin >> mausac;
    }
};
class AoNganTay : public Ao {
public:
    bool coCO;
    AoNganTay() {
        loai = 3;
    }
    void Nhap() {
        Ao::Nhap();
        cin >> coCO;
    }
};
class AoDaiTay : public Ao {
public:
    float chieu_dai_ong_tay;
    AoDaiTay() {
        loai = 4;
    }
    void Nhap() {
        Ao::Nhap();
        cin >> chieu_dai_ong_tay;
    }
};
class Mu : public VatPham {
public:
    int level;
    float buff;
    void Nhap() {
        VatPham::Nhap();
        cin >> level;
    }
};
class MuSat : public Mu {
public:
    MuSat() {
        buff = 1;
        loai = 5;
    }
    float GiaTriThuc() {
        return 0;
    }
};
class MuBac : public Mu {
public:
    MuBac() {
        buff = 1.5;
        loai = 6;
    }
};
class MuVang : public Mu {
public:
    MuVang() {
        buff = 3;
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
            VatPham* vatpham;
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
                vatpham = new AoNganTay;
                break;
            case 4:
                vatpham = new AoDaiTay;
                break;
            case 5:
                vatpham = new MuSat;
                break;
            case 6:
                vatpham = new MuBac;
                if (VatPham::buff == 1)
                    VatPham::buff = 1.5;
                break;
            case 7:
                vatpham = new MuVang;
                VatPham::buff = 3;
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
    float TongGiaTri() {
        float sum = 0;
        for (VatPham* x : list) {
            if (x->loai >= 5 && x->loai <= 7) {
                sum = sum + x->GiaTriThuc();
            }
            else
            {
                sum = sum + x->GiaTriThuc() * VatPham::buff;
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