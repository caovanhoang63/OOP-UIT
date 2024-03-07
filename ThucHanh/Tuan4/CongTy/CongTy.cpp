#include <iostream>
using namespace std;

static int TongSoSP = 0;
static int TongSoNLV = 0;


class NhanVien {
public:
    string hoTen;
    virtual void Nhap() {
        cin >> hoTen;
    }
    void Xuat() {
        cout << hoTen << ": " << this->TinhLuong() << endl;
    }
    virtual float TinhLuong() = 0;
};

class NVSX : public NhanVien {
public:
    float luongCB;
    int soSP;
    void Nhap() {
        NhanVien::Nhap();
        cin >> luongCB >> soSP;
        TongSoSP += soSP;
    }

    float TinhLuong() {
        return luongCB + soSP * 5;
    }
};

class NVVP : public NhanVien {
public:
    int soNLV;
    void Nhap() {
        NhanVien::Nhap();
        cin >> soNLV;
        TongSoNLV += soNLV;
    }

    float TinhLuong() {
        return soNLV * 100;
    }
};

class Sep : public NhanVien {
public:
    float TinhLuong() {
        return 100 + TongSoNLV * 40 + TongSoSP * 2;
    }

};
using namespace std;

int main()
{
    int n;
    cin >> n;
    NhanVien** dsNV = new NhanVien * [n];
    // NhanVien* dsNV[100];
    for (int i = 0; i < n; i++) {
        int loai;
        cin >> loai;
        if (loai == 1) {
            dsNV[i] = new NVSX();
        }

        if (loai == 2) {
            dsNV[i] = new NVVP();
        }

        if (loai == 3) {
            dsNV[i] = new Sep();
        }

        dsNV[i]->Nhap();
    }

    for (int i = 0; i < n; i++) {
        dsNV[i]->Xuat();
    }
    return 0;
}