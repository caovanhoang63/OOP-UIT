#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class VuKhi {
public:
    int loai;
    float sat_thuong;
    int so_luot;
    virtual void Nhap() {
        cin >> sat_thuong >> so_luot;
    }
    virtual float TanCong(float maxhp = 0) = 0;
};
class TayKhong : public VuKhi {
public:
    TayKhong() {
        loai = 0;
    }
    float TanCong(float maxhp) {
        return maxhp * 0.1;
    }
};
class Dao : public VuKhi {
public:
    float chieu_dai;
    Dao() {
        loai = 1;
    }
    void Nhap() {
        VuKhi::Nhap();
        cin >> chieu_dai;
    }
    float TanCong(float = 0){
        so_luot--;
        return chieu_dai * sat_thuong;
    }
};
class Cung : public VuKhi {
public:
    int mui_ten;
    Cung() {
        loai = 2;
    }
    void Nhap() {
        VuKhi::Nhap();
        cin >> mui_ten;
    }
    float TanCong(float  =0 ) {
        so_luot--;
        return  sat_thuong * mui_ten/2;
    }
};
class APhu {
public:
    float maxhp;
    float hp;
    vector<VuKhi*> danhsach;
    TayKhong taykhong;
    void Nhap() {
        cin >> maxhp;
        hp = maxhp;
        int n,loai;
        cin >> n;
        for (int i = 0; i < n; i++) {
            VuKhi* temp; 
            cin >> loai;
            switch (loai)
            {
            case 1:
                temp = new Dao;
                break;
            case 2:
                temp = new Cung;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                danhsach.push_back(temp);
            }
        }
    }
    float TanCong() {
        float damage = 0;
        if (!danhsach.empty()) {
            damage = danhsach.front()->TanCong();
            if (danhsach.front()->so_luot <= 0)
                danhsach.erase(danhsach.begin());
        }
        else {
            hp -= 0.1 * maxhp;
            damage = taykhong.TanCong(maxhp);
        }
        return damage;
    }
};
class ThuDu {
public:
    float hp;
    float sat_thuong;
    int loai;
    virtual void Nhap() {
        cin >> hp >> sat_thuong;
    }
    virtual float TanCong() = 0;
    virtual void NhanSatThuong(float damage) {
        hp -= damage;
    }
};
class BoTot : public ThuDu {
public:
    int so_lan_chiu_danh;
    BoTot() {
        loai = 1;
    }
    void NhanSatThuong(float damage) {
        ThuDu::NhanSatThuong(damage);
        so_lan_chiu_danh--;
        if (so_lan_chiu_danh == 0)
        {
            this->hp = -99999;
        }
    }
    void Nhap() {
        ThuDu::Nhap();
        cin >> so_lan_chiu_danh;
    }
    float TanCong() {
        return sat_thuong;
    }
};
class Ho : public ThuDu {
public:
    Ho() {
        loai = 2;
    }
    float TanCong() {
        return sat_thuong * 1.5;
    }
};
class QuanLy {
public:
    vector<ThuDu*> danhsach;
    APhu a_phu;
    void Nhap() {
        a_phu.Nhap();
        int n,loai;
        cin >> n;
        for (int i = 0; i < n; i++) {
            ThuDu* temp;
            cin >> loai;
            switch (loai)
            {
            case 1:
                temp = new BoTot;
                break;
            case 2:
                temp = new Ho;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp != NULL) {
                temp->Nhap();
                danhsach.push_back(temp);
            }
        }
    }
    bool GiaoTranh() {
        while (a_phu.hp > 0 && !danhsach.empty()) {
            danhsach.front()->NhanSatThuong( a_phu.TanCong());
            if (danhsach.front()->hp <= 0) 
            {
                danhsach.erase(danhsach.begin());
                continue;
            }
            if (danhsach.empty())
                break;
            a_phu.hp -= danhsach.front()->TanCong();
        }
        if (a_phu.hp > 0)
            return 1;
        return 0;
    }
    void KetQua() {
        if (GiaoTranh() == 1) {
            cout << "A Phu chien thang, hp con lai: " << a_phu.hp << ", so vu khi con lai: " << a_phu.danhsach.size() << endl;
        }
        else{
            cout << "A Phu that bai, so thu du con lai: " << danhsach.size();
        }
    }
};
int main() {
    QuanLy temp;
    temp.Nhap();
    temp.KetQua();
    return 0;
}