#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class ThapPhao {
public:
    float size;
    int num_ammos;
    virtual float TanCong() = 0;
    ThapPhao(int num_ammos) {
        this->num_ammos = num_ammos;
    }
    void Nhap() {
        cin >> num_ammos;
    }
};
class ThapPhao_ML20S : public ThapPhao{
public:
    int num_crew;
    ThapPhao_ML20S(int num_ammos,int num_crew)
        :ThapPhao(num_ammos){
        this->num_crew = num_crew;
        size = 152;
    }
    float TanCong() {
        return (float)num_crew / 4 * size * num_ammos;
    }
};
class ThapPhao_F34 : public ThapPhao {
public:
    ThapPhao_F34(int num_ammos)
    :ThapPhao(num_ammos){
        size = 76.2;
    }
    float TanCong() {
        return 3 * size * num_ammos;
    }
};
class ThapPhao_D25T : public ThapPhao {
public:
    ThapPhao_D25T(int num_ammos): ThapPhao(num_ammos){
        size = 122;
    }
    float TanCong() {
        return 3 * size * num_ammos;
    }
};
class ThapPhao_M65L : public ThapPhao {
public:
    int num_crew;
    ThapPhao_M65L(int num_ammos, int num_crew): ThapPhao(num_ammos) {
        this->num_crew = num_crew;
        size = 130;
    }
    float TanCong() {
        return (float)num_crew / 4 * size * num_ammos;
    }
};
class DongCo {
public:
    int ma_luc;
    float xang;
    DongCo(float xang) {
        this->xang = xang;
    }
    virtual void TieuThu(float weight,float quangduong) = 0;
};
class DongCo_V2 : public DongCo {
public:
    DongCo_V2(float xang) : DongCo(xang) {
        ma_luc = 500;
    }
    void TieuThu(float weight, float quangduong) {
        xang -= (quangduong / 100) * (450 / weight);
    }
};
class DongCo_V2K : public DongCo {
public:
    DongCo_V2K(float xang): DongCo(xang) {
        ma_luc = 600;
    }
    void TieuThu(float weight,float quangduong) {
        xang -= (quangduong / 100) * (450 / weight);
    }
};
class DongCo_2DG8M : public DongCo {
public:
    DongCo_2DG8M(float xang): DongCo(xang) {
        ma_luc = 1000;
    }
    void TieuThu(float weight,float quangduong) {
        xang -= (quangduong / 100) * (400 / weight);
    }
};
class Tank {
public:
    ThapPhao* thap_phao;
    DongCo* dong_co;
    float weight;
    int num_crew;
    int id;
    string ten;
    float xang_ban_dau;
    int so_dan_ban_dau;
    virtual void Nhap() {
        cin >> weight >> num_crew >> so_dan_ban_dau >> xang_ban_dau;
    }
    virtual float HieuSuat() = 0;
    void Xuat() {
        cout << ten << ", ";
        cout << "weight: " << weight << ", ";
        cout << "number of crews: " << num_crew << ", ";
        cout << "damage: " << thap_phao->TanCong() << ", ";
        cout << "performance: " << HieuSuat() << "%" << endl;
    }
    void TanCong(int so_dan_da_ban) {
        thap_phao->num_ammos -= so_dan_da_ban;
    }
    void DiChuyen(float quang_duong) {
        dong_co->TieuThu(weight, quang_duong);
    }
};
class Tank_SU152: public Tank {
public:
    Tank_SU152() {
        id = 1;
        ten = "SU152";
    }
    void Nhap() {
        Tank::Nhap();
        thap_phao = new ThapPhao_ML20S(so_dan_ban_dau,num_crew);
        dong_co = new DongCo_V2K(xang_ban_dau);
    }
    float HieuSuat() {
        return (float)100*thap_phao->num_ammos/ so_dan_ban_dau;
    }

};
class Tank_KV2: public Tank {
public:
    Tank_KV2() {
        id = 2;
        ten = "KV2";
    }
    void Nhap() {
        Tank::Nhap();
        thap_phao = new ThapPhao_F34(so_dan_ban_dau);
        dong_co = new DongCo_V2(xang_ban_dau);
    }
    float HieuSuat() {
        return (float)100 * thap_phao->num_ammos/ so_dan_ban_dau;
    }
};
class Tank_IS : public Tank {
public:
    Tank_IS() {
        id = 3;
        ten = "IS";
    }
    void Nhap() {
        Tank::Nhap();
        thap_phao = new ThapPhao_D25T(so_dan_ban_dau);
        dong_co = new DongCo_V2K(xang_ban_dau);
    }
    float HieuSuat() {
        return (float)100*dong_co->xang / xang_ban_dau;
    }
};
class Tank_Object279 : public Tank {
public:
    Tank_Object279() {
        id = 4;
        ten = "Object279";
    }
    void Nhap() {
        Tank::Nhap();
        thap_phao = new ThapPhao_M65L(so_dan_ban_dau,num_crew);
        dong_co = new DongCo_2DG8M(xang_ban_dau);
    }
    float HieuSuat() {
        return (float)100 *num_crew/4;
    }
};
class QuanLy {
public:
    vector<Tank*> danhsach;
    float quangduong;
    int dan_da_ban;
    void Nhap() {
        int n,loai;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Tank* temp;
            cin >> loai;
            switch (loai)
            {
            case 1:
                temp = new Tank_SU152;
                break;
            case 2:
                temp = new Tank_KV2;
                break;
            case 3:
                temp = new Tank_IS;
                break;
            case 4:
                temp = new Tank_Object279;
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
        cin >> quangduong >> dan_da_ban;
    }
    void VanHanh() {
        for (auto& x : danhsach) {
            x->TanCong(dan_da_ban);
            x->DiChuyen(quangduong);
        }
    }
    void Xuat() {
        for (auto x : danhsach) {
            x->Xuat();
        }
    }
};
int main() {
    QuanLy a;
    a.Nhap();
    a.VanHanh();
    a.Xuat();
    return 0;
}


