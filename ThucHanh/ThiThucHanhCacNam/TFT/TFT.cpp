#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Tribe{
public:
    string name_toc;
    int type_toc;
};
class Class {
public:
    string name_he;
    int type_he;
};
class Champion {
public:
    Tribe* Toc;
    Class* He;
    string name;
    int price,type;
    float attack, defend;
    virtual double calcDamage(int soluot) = 0; // pure virtual function
};
class CongNghe : public Tribe {
public:
    CongNghe() {
        name_toc = "Cong Nghe";
        type_toc = 1;
    }
    
};
class TienCong : public Tribe {
public:
    TienCong() {
        name_toc = "Tien Cong";
        type_toc = 2;
    }
};
class DauSi :public Class {
public:
    DauSi() {
        name_he = "Dau Si";
        type_he = 1;
    }
};
class Jarvan : public Champion{
public:
    Jarvan() {
        Toc = new CongNghe;
        He = new DauSi;
        name = "Jarvan";
        price = 1;
        type = 1;
    }
    double calcDamage(int soluot) {
        return soluot * 2 * defend;
    }
   
};
class Sivir : public Champion {
public:
    Sivir() {
        Toc = new CongNghe;
        He = NULL;
        name = "Sivir";
        price = 4;
        type = 3;
    }
    double calcDamage(int soluot) {
        return attack * soluot * 2;
    }
};
class Reksai : public Champion {
public:
    Reksai() {
        Toc = new TienCong;
        He = new DauSi;
        name = "Reksai";
        price = 2;
        type = 2;
    }
    double calcDamage(int soluot) {
        int tong = 0;
        for (int i = 1; i <= soluot; i++) {
            if (i % 4 == 0) {
                tong += attack * 2;
            }
            else
            {
                tong += attack;
            }
        }
        return tong;
    }
};
class Illaoi : public Champion, public TienCong, public DauSi {
public:
    Illaoi() {
        Toc = new TienCong;
        He = new DauSi;
        name = "Illaoi";
        price = 1;
        type = 4;
    }
    double calcDamage(int soluot) {
        return (attack + defend) / 2 * soluot;
    }
};
class Arena {
public:
    vector<Champion*> list;
    int sotuong;
    int soluot;
    void init(int sotuong, int soluot) {
        this->sotuong = sotuong;
        this->soluot = soluot;
    }
    void Nhap() {
        for (int i = 0; i < sotuong; i++) {
            int type;
            cin >> type;
            Champion* champion{};
            switch (type)
            {
            case 1:
                champion = new Jarvan;
                break;
            case 2:
                champion = new Reksai;
                break;
            case 3:
                champion = new Sivir;
                break;
            case 4:
                champion = new Illaoi;
            }
            cin >> champion->attack;
            cin >> champion->defend;
            list.push_back(champion);
        }
    }
    void calcBonus(){
        
        map <int,Champion*> distinc ;
        for (auto x : list) {
            distinc[x->type] = x;
        }
        int countDauSi = 0 ; 
        int countCongNghe = 0;
        int countTienCong = 0;
        // Toc Cong Nghe 1
        // Toc tien cong 2
        // He dau si 1
        for (auto x : distinc) {
            if (x.second->He != NULL && x.second->He->type_he == 1)
               countDauSi++;
            if (x.second->Toc->type_toc == 1)
                countCongNghe++;
            if (x.second->Toc->type_toc == 2)
                countTienCong++;
        }
        if (countDauSi == 2) {
            for (auto x : list) {
                if (x->He->type_he ==  1) {
                    x->defend += 15;
                }
            }
        }
        else if (countDauSi == 3) {
            for (auto x : list) {
                if (x->He != NULL && x->He->type_he == 1) {
                    x->defend += 30;
                }
            }
        }
        if (countCongNghe == 2) {
            for (auto x : list) {
                if (x->Toc->type_toc == 1  ) {
                    x->defend += 15;
                    x->attack += 15;
                }
            }
        }
        if (countTienCong == 2) {
            for (auto x : list) {
                if (x->Toc->type_toc == 2) {
                    x->attack += 30;
                }
            }
        }
    }
    void PrintArena() {
        int sumPrice = 0;
        for (auto x : list) {
            sumPrice += x->price;
            cout << x->name<<" - sat thuong gay ra: "<<x->calcDamage(soluot) << endl;
        }
        cout << "Tong gia tri: " << sumPrice<<endl;
    }
};

int main() {
    Arena a;
    int n, m;
    cin >> n;
    cin >> m;
    a.init(n, m);
    a.Nhap();
    a.calcBonus();
    a.PrintArena();
    return 0;
}