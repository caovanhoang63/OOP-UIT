#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Chai {
public:
    Chai(){}
    int loai;
    virtual void Nhap() = 0;
    virtual float DienTich() = 0;
    virtual float TheTich() = 0;
};

class ChaiTru : public Chai {
public:
    float chieu_cao;
    float ban_kinh;
    ChaiTru() {
        loai = 1;
    }
    void Nhap() {
        cin >> chieu_cao;
        cin >> ban_kinh;
    }
    float DienTich() {
        return 2 * 3.14 * ban_kinh * chieu_cao;
    }
    float TheTich() {
        return 3.14 * ban_kinh * ban_kinh * chieu_cao;
    }
};
class ChaiHopChuNhat : public Chai {
public:
    float chieu_cao;
    float chieu_dai;
    float chieu_rong;
    ChaiHopChuNhat() {
        loai = 2;
    }
    void Nhap() {
        cin >> chieu_cao >> chieu_dai >> chieu_rong;
    }
    float DienTich() {
        return (chieu_dai + chieu_rong) * 2 * chieu_cao + chieu_dai * chieu_rong * 2;
    }
    float TheTich() {
        return chieu_cao * chieu_dai * chieu_rong;
    }
};
class ChaiLapPhuong : public Chai {
public:
    float canh;
    ChaiLapPhuong() {
        loai = 3;
    }
    void Nhap() {
        cin >> canh;
    }
    float DienTich() {
        return canh * canh * 6;
    }
    float TheTich() {
        return canh * canh * canh;
    }
};
int main() {
    int n,loai; 
    float dientich = 0,thetich = 0;
    cin >> n;
    Chai** danhsach = new Chai * [n];
    for (int i = 0; i < n; i++) {
        Chai* temp;
        cin >> loai;
        switch (loai)
        {
        case 1:
            temp = new ChaiTru;
            break;
        case 2:
            temp = new ChaiHopChuNhat;
            break;
        case 3:
            temp = new ChaiLapPhuong;
            break;
        default:
            temp = NULL;
            break;
        }
        temp->Nhap();
        danhsach[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        dientich += danhsach[i]->DienTich();
        thetich += danhsach[i]->TheTich();
    }
    cout << "Dien tich chai vo: " << dientich << endl;
    cout << "Luong nuoc tren mat dat : " << thetich/10 << endl;
    return 0;
}
