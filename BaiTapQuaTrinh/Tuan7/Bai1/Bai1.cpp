#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ngay
{
private:
    int ngay;
    int thang;
    int nam;

public:
    virtual void Nhap()
    {
        cout << "Nhap ngay: ";
        cin >> ngay;
        cout << "Nhap thang: ";
        cin >> thang;
        cout << "Nhap nam: ";
        cin >> nam;
    }
    void Xuat()
    {
        cout << ngay << "/" << thang << "/" << nam << endl;
    }
};
class NhanVien
{
protected:
    string ten;
    Ngay ngay_sinh;
    int luong;

public:
    NhanVien() {}
    virtual void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, ten);
        cout << "Nhap ngay sinh: " << endl;
        ngay_sinh.Nhap();
    }
    virtual void Xuat()
    {

        cout << "Ho ten: " << ten << endl;
        cout << "Ngay sinh: ";
        ngay_sinh.Xuat();
        cout << "Luong: " << luong << endl;
    };
    virtual void TinhLuong() = 0;
};

class NhanVienSanXuat : public NhanVien
{
private:
    int luong_co_ban;
    int san_pham;

public:
    NhanVienSanXuat() {}
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "Nhap luong co ban: ";
        cin >> luong_co_ban;
        cout << "Nhap so san pham: ";
        cin >> san_pham;
    }
    void Xuat()
    {
        cout << "Nhan vien san xuat: " << endl;
        NhanVien::Xuat();
        cout << "So san pham: " << san_pham << endl;
        cout << "Luong co ban : " << luong_co_ban << endl;
    }
    void TinhLuong()
    {
        luong = luong_co_ban * san_pham * 5000;
    }
};
class NhanVienVanPhong : public NhanVien
{
private:
    int so_ngay_lam;

public:
    NhanVienVanPhong() {}
    void Nhap() 
    {
        NhanVien::Nhap();
        cout << "Nhap so ngay lam viec: ";
        cin >> so_ngay_lam;
    }
    void Xuat()
    {
        cout << "Nhan vien van phong" << endl;
        NhanVien::Xuat();

        cout << "So ngay lam viec : " << so_ngay_lam << endl;
    }
    void TinhLuong()
    {
        luong = so_ngay_lam * 100000;
    }
};
class CongTi {
protected:
    vector<NhanVien*> danh_sach_nhan_vien;
public:
    void Nhap() {
        cout << "Nhap so luong nhan vien: ";
        int n,type;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "Nhap nhan vien thu " << i + 1<<endl;
            cout << "Nhap loai nhan vien: ";
            cout << "\n1. Nhan vien van phong\n2. Nhan vien san xuat\n";
            cin >> type;
            NhanVien* temp;
            switch (type)
            {
            case 1: 
                temp = new NhanVienVanPhong;
                break;
            case 2:
                temp = new NhanVienSanXuat;
                break;
            default:
                temp = NULL;
                break;
            }
            if (temp == NULL)
                return;
            temp->Nhap();
            danh_sach_nhan_vien.push_back(temp);
        }
    }
    void TinhLuong() {
        for (NhanVien* &a : danh_sach_nhan_vien)
            a->TinhLuong();
    }
    void Xuat() {
        cout << "Danh sach nhan vien cua cong ti: "<<endl;
        for (int i = 0; i < danh_sach_nhan_vien.size(); i++)
        {
            cout << "Thong tin cua nhan vien thu " << i + 1<<endl;
            danh_sach_nhan_vien[i]->Xuat();
        }
    }
};
int main()
{
    CongTi UIT;
    UIT.Nhap();
    UIT.TinhLuong();
    UIT.Xuat();
    return 0;
}