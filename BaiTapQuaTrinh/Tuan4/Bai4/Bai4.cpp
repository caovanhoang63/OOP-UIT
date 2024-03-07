#include <iostream>
#include <vector>
using namespace std;
class DonThuc
{
private:
    int _bac;
    float _so_hang;

public:
    DonThuc(){};
    DonThuc(int so_hang, int bac)
    {
        this->_bac = bac;
        this->_so_hang = so_hang;
    }
    void Enter()
    {
        cout << "Nhap so hang: ";
        cin >> _so_hang;
        cout << "Nhap so bac: ";
        cin >> _bac;
    }
    void Print()
    {
        if (_bac != 0)
        {
            cout << _so_hang << "x^(" << _bac << ")";
        }
        else
            cout << _so_hang;
    }
    friend class DaThuc;
};
class DaThuc
{
private:
    vector<DonThuc> _da_thuc;

public:
    DaThuc() {}
    DaThuc(vector<DonThuc> da_thuc)
    {
        this->_da_thuc = da_thuc;
    }
    void Cong(DaThuc);
    void Cong(DonThuc);
    void Nhan(DaThuc);
    void Nhan(DonThuc);
    void RutGon();
    int getBac();
    int getMinBac();
    void Print();
    void Enter();
};

int main()
{
    DaThuc a;
    a.Enter();
    a.Print();
    return 0;
}

void DaThuc::Cong(DaThuc a)
{
    this->_da_thuc.insert(this->_da_thuc.end(), a._da_thuc.begin(), a._da_thuc.end());
    this->RutGon();
}
void DaThuc::Cong(DonThuc a)
{
    this->_da_thuc.push_back(a);
    this->RutGon();
}
void DaThuc::Nhan(DonThuc a)
{
    for (auto x : this->_da_thuc)
    {
        x._so_hang *= a._so_hang;
        x._bac += a._bac;
    }
    this->RutGon();
}
void DaThuc::Nhan(DaThuc a)
{
    for (auto x : a._da_thuc)
    {
        this->Nhan(x);
    }
    this->RutGon();
}
// void DaThuc::RutGon()
// {
//     int max = this->getBac();
//     int min = this->getMinBac();
//     for (int i = min; i <= max; i++)
//     {
//         DonThuc temp(0, i);
//         for (vector<DonThuc>::iterator it = _da_thuc.begin(); it != _da_thuc.end(); it++)
//         {
//             if ((*it)._bac == i)
//             {
//                 temp._so_hang += (*it)._so_hang;
//                 _da_thuc.erase(it);
//                 it--;
//             }
//         }
//         if (temp._so_hang != 0)
//             _da_thuc.push_back(temp);
//     }
// }
void DaThuc::RutGon()
{
    int max = this->getBac();
    int min = this->getMinBac();
    for (int i = min; i <= max; i++)
    {
        DonThuc temp(0, i);
        for (int j = 0; j < _da_thuc.size(); j++)
        {
            if (_da_thuc[j]._bac == i)
            {
                temp._so_hang += _da_thuc[j]._so_hang;
                _da_thuc.erase(_da_thuc.begin() + j);
                j--;
            }
        }
        if (temp._so_hang != 0)
            _da_thuc.push_back(temp);
    }
}

int DaThuc::getBac()
{
    int max = 0;
    for (auto x : _da_thuc)
        if (x._bac > max)
            max = x._bac;
    return max;
}
int DaThuc::getMinBac()
{
    int min = _da_thuc[0]._bac;
    for (auto x : _da_thuc)
        if (x._bac < min)
            min = x._bac;
    return min;
}
void DaThuc::Print()
{
    this->RutGon();
    for (auto x : _da_thuc)
    {
        if (x._so_hang > 0)
        {
            cout << "+";
            x.Print();
        }
        else
        {
            x.Print();
        }
    }
}
void DaThuc::Enter()
{
    cout << "So phan tu cua da thuc: ";
    int n;
    cin >> n;
    DonThuc temp;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap don thuc thu " << i << ":" << endl;
        temp.Enter();
        _da_thuc.push_back(temp);
    }
}