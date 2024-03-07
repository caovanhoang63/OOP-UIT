#include <iostream>

class Diem {
private:
    int x;
    int y;

public:
    Diem(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Diem& diem) {
        os << "(" << diem.x << ", " << diem.y << ")";
        return os;
    }
};

class DaGiac {
protected:
    int SoDinh;
    Diem* Dinh;

public:
    DaGiac(int SoDinh = 0) {
        this->SoDinh = SoDinh;
        this->Dinh = new Diem[SoDinh];
    }

    ~DaGiac() {
        delete[] Dinh;
    }

    virtual void nhap() {
        std::cout << "Nhap toa do cac dinh: " << std::endl;
        for (int i = 0; i < SoDinh; i++) {
            int x, y;
            std::cout << "Dinh " << i + 1 << ": "<<std::endl;
            std::cout << "Nhap x: ";
            std:: cin >> x;
            std::cout << "Nhap y: ";
            std::cin >> y;
            Dinh[i].setX(x);
            Dinh[i].setY(y);
        }
    }

    virtual void xuat() const {
        std::cout << "Cac dinh cua da giac: ";
        for (int i = 0; i < SoDinh; i++) {
            std::cout << Dinh[i] << " ";
        }
        std::cout << std::endl;
    }

    virtual void tinhTien(int dx, int dy) {
        for (int i = 0; i < SoDinh; i++) {
            Dinh[i].setX(Dinh[i].getX() + dx);
            Dinh[i].setY(Dinh[i].getY() + dy);
        }
    }
};

class TamGiac : public DaGiac {
public:
    TamGiac() : DaGiac(3) {}

    void nhap() override {
        std::cout << "Nhap toa do cac dinh cua tam giac: " << std::endl;
        DaGiac::nhap();
    }

    void xuat() const override {
        std::cout << "Tam giac co ";
        DaGiac::xuat();
    }
};

class TuGiac : public DaGiac {
public:
    TuGiac() : DaGiac(4) {}

    void nhap() override {
        std::cout << "Nhap toa do cac dinh cua tu giac: " << std::endl;
        DaGiac::nhap();
    }

    void xuat() const override {
        std::cout << "Tu giac co ";
        DaGiac::xuat();
    }
};

class HinhBinhHanh : public DaGiac {
public:
    HinhBinhHanh() : DaGiac(4) {}

    void nhap() override {
        std::cout << "Nhap toa do cac dinh cua hinh binh hanh: " << std::endl;

        do {
            DaGiac::nhap();
            if (!kiemTraHopLe())
                std::cout << "Nhap sai, vui long nhap lai" << std::endl;
            else
                break;
        } while (true);
    }

    void xuat() const override {
        std::cout << "Hinh binh hanh co ";
        DaGiac::xuat();
    }

private:
    bool kiemTraHopLe() const {

        int xa = Dinh[0].getX();
        int ya = Dinh[0].getY();
        int xb = Dinh[1].getX();
        int yb = Dinh[1].getY();
        int xc = Dinh[2].getX();
        int yc = Dinh[2].getY();
        int xd = Dinh[3].getX();
        int yd = Dinh[3].getY();

        int vectoAB_x = xb - xa;
        int vectoAB_y = yb - ya;
        int vectoCD_x = xd - xc;
        int vectoCD_y = yd - yc;
        int vectoBC_x = xc - xb;
        int vectoBC_y = yc - yb;
        int vectoDA_x = xa - xd;
        int vectoDA_y = ya - yd;

        return (vectoAB_x * vectoCD_y - vectoAB_y * vectoCD_x == 0) &&
            (vectoBC_x * vectoDA_y - vectoBC_y * vectoDA_x == 0);
    }
};


class HinhChuNhat : public DaGiac {
public:
    HinhChuNhat() : DaGiac(4) {}

    void nhap() override {
        std::cout << "Nhap toa do cac dinh cua hinh chu nhat: " << std::endl;

        do {
            DaGiac::nhap();
            if (!kiemTraHopLe())
                std::cout << "Nhap sai, vui long nhap lai" << std::endl;
            else
                break;
        } while (true);
    }

    void xuat() const override {
        std::cout << "Hinh chu nhat co ";
        DaGiac::xuat();
    }

private:
    bool kiemTraHopLe() const {

        int xa = Dinh[0].getX();
        int ya = Dinh[0].getY();
        int xb = Dinh[1].getX();
        int yb = Dinh[1].getY();
        int xc = Dinh[2].getX();
        int yc = Dinh[2].getY();
        int xd = Dinh[3].getX();
        int yd = Dinh[3].getY();

        int dotProductABBC = (xb - xa) * (xc - xb) + (yb - ya) * (yc - yb);
        int dotProductBCCD = (xc - xb) * (xd - xc) + (yc - yb) * (yd - yc);
        int dotProductCDDA = (xd - xc) * (xa - xd) + (yd - yc) * (ya - yd);
        int dotProductDAAE = (xa - xd) * (xb - xa) + (ya - yd) * (yb - ya);

        return dotProductABBC == 0 && dotProductBCCD == 0 && dotProductCDDA == 0 && dotProductDAAE == 0;
    }
};


class HinhVuong : public DaGiac {
public:
    HinhVuong() : DaGiac(4) {}

    void nhap() override {
        std::cout << "Nhap toa do cac dinh cua hinh vuong: " << std::endl;
        do {
            DaGiac::nhap();
            if (!kiemTraHopLe())
                std::cout << "Nhap sai, vui long nhap lai" << std::endl;
            else
                break;
        } while (true);
    }

    void xuat() const override {
        std::cout << "Hinh vuong co ";
        DaGiac::xuat();
    }

private:
    bool kiemTraHopLe() const {
        int xa = Dinh[0].getX();
        int ya = Dinh[0].getY();
        int xb = Dinh[1].getX();
        int yb = Dinh[1].getY();
        int xc = Dinh[2].getX();
        int yc = Dinh[2].getY();
        int xd = Dinh[3].getX();
        int yd = Dinh[3].getY();
        int edgeAB = sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
        int edgeBC = sqrt(pow(xc - xb, 2) + pow(yc - yb, 2));
        int edgeCD = sqrt(pow(xd - xc, 2) + pow(yd - yc, 2));
        int edgeDA = sqrt(pow(xa - xd, 2) + pow(ya - yd, 2));
        int dotProductABBC = (xb - xa) * (xc - xb) + (yb - ya) * (yc - yb);
        int dotProductBCCD = (xc - xb) * (xd - xc) + (yc - yb) * (yd - yc);
        int dotProductCDDA = (xd - xc) * (xa - xd) + (yd - yc) * (ya - yd);
        int dotProductDAAE = (xa - xd) * (xb - xa) + (ya - yd) * (yb - ya);

        return edgeAB == edgeBC && edgeBC == edgeCD && edgeCD == edgeDA
            && dotProductABBC == 0 && dotProductBCCD == 0 && dotProductCDDA == 0 && dotProductDAAE == 0;
    }
};

int main() {
    DaGiac* daGiac;

    std::cout << "Chon hinh da giac (1 - Tam giac, 2 - Tu giac, 3 - Hinh binh hanh, 4 - Hinh chu nhat, 5 - Hinh vuong): ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        daGiac = new TamGiac();
    }
    else if (choice == 2) {
        daGiac = new TuGiac();
    }
    else if (choice == 3) {
        daGiac = new HinhBinhHanh();
    }
    else if (choice == 4) {
        daGiac = new HinhChuNhat();
    }
    else if (choice == 5) {
        daGiac = new HinhVuong();
    }
    else {
        std::cout << "Lua chon khong hop le." << std::endl;
        return 0;
    }

    daGiac->nhap();
    daGiac->xuat();

    int dx, dy;
    std::cout << "Nhap vecto tinh tien (dx, dy): ";
    std::cin >> dx >> dy;

    daGiac->tinhTien(dx, dy);

    std::cout << "Da tinh tien: ";
    daGiac->xuat();

    delete daGiac;

    return 0;
}

