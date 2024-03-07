#include <iostream>

class Diem {
private:
	float x;
	float y;

public:
	Diem() {
		x = y = 0;
	}

	Diem(float x, float y) {
		this->x = x;
		this->y = y;
	}

	float getX() const {
		return x;
	}

	float getY() const {
		return y;
	}

	void setX(float x) {
		this->x = x;
	}

	void setY(float y) {
		this->y = y;
	}

	void NhapDiem() {
		std::cout << "Nhap toa do x: ";
		std::cin >> x;
		std::cout << "Nhap toa do y: ";
		std::cin >> y;
	}

	void XuatDiem() const {
		std::cout << "(" << x << ", " << y << ")";
	}
};

class TuGiac {
protected:
	Diem Dinh1, Dinh2, Dinh3, Dinh4;

public:
	TuGiac() {
		Dinh1 = Diem();
		Dinh2 = Diem();
		Dinh3 = Diem();
		Dinh4 = Diem();
	}

	TuGiac(Diem d1, Diem d2, Diem d3, Diem d4) {
		Dinh1 = d1;
		Dinh2 = d2;
		Dinh3 = d3;
		Dinh4 = d4;
	}

	void setDinh1(Diem d) {
		Dinh1 = d;
	}

	void setDinh2(Diem d) {
		Dinh2 = d;
	}

	void setDinh3(Diem d) {
		Dinh3 = d;
	}

	void setDinh4(Diem d) {
		Dinh4 = d;
	}

	Diem getDinh1() const {
		return Dinh1;
	}

	Diem getDinh2() const {
		return Dinh2;
	}

	Diem getDinh3() const {
		return Dinh3;
	}

	Diem getDinh4() const {
		return Dinh4;
	}

	virtual void Nhap() {
		std::cout << "Nhap toa do cua diem 1:\n";
		Dinh1.NhapDiem();
		std::cout << "Nhap toa do cua diem 2:\n";
		Dinh2.NhapDiem();
		std::cout << "Nhap toa do cua diem 3:\n";
		Dinh3.NhapDiem();
		std::cout << "Nhap toa do cua diem 4:\n";
		Dinh4.NhapDiem();
	}

	void Xuat() const {
		std::cout << "Toa do cua diem 1: ";
		Dinh1.XuatDiem();
		std::cout << "\nToa do cua diem 2: ";
		Dinh2.XuatDiem();
		std::cout << "\nToa do cua diem 3: ";
		Dinh3.XuatDiem();
		std::cout << "\nToa do cua diem 4: ";
		Dinh4.XuatDiem();
		std::cout << std::endl;
	}
};
class HinhThang : public TuGiac {
public:
	HinhThang() : TuGiac() {
	}

	HinhThang(Diem d1, Diem d2, Diem d3, Diem d4) : TuGiac(d1, d2, d3, d4) {
		if (!(d1.getY() == d2.getY() && d3.getY() == d4.getY())) {
			Dinh1 = Diem();
			Dinh2 = Diem();
			Dinh3 = Diem();
			Dinh4 = Diem();
		}
	}

	void Nhap() {
		Diem d1, d2, d3, d4;
		bool hopLe = false;

		do {
			std::cout << "Nhap toa do cua diem 1:\n";
			d1.NhapDiem();
			std::cout << "Nhap toa do cua diem 2:\n";
			d2.NhapDiem();
			std::cout << "Nhap toa do cua diem 3:\n";
			d3.NhapDiem();
			std::cout << "Nhap toa do cua diem 4:\n";
			d4.NhapDiem();
			if (d1.getY() == d2.getY() && d3.getY() == d4.getY()) {
				setDinh1(d1);
				setDinh2(d2);
				setDinh3(d3);
				setDinh4(d4);
				hopLe = true;
			}
			else {
				std::cout << "Nhap khong hop le. Hinh thang khong thoa man dieu kien. Vui long nhap lai.\n";
			}
		} while (!hopLe);
	}
};

class HinhBinhHanh : public TuGiac {
public:
	HinhBinhHanh() : TuGiac() {
	}

	HinhBinhHanh(Diem d1, Diem d2, Diem d3, Diem d4) : TuGiac(d1, d2, d3, d4) {
		if (!((d2.getX() - d1.getX()) == (d4.getX() - d3.getX()) && (d2.getY() - d1.getY()) == (d4.getY() - d3.getY()))) {
			Dinh1 = Diem();
			Dinh2 = Diem();
			Dinh3 = Diem();
			Dinh4 = Diem();
		}
	}

	void Nhap() {
		Diem d1, d2, d3, d4;
		bool hopLe = false;

		do {
			std::cout << "Nhap toa do cua diem 1:\n";
			d1.NhapDiem();
			std::cout << "Nhap toa do cua diem 2:\n";
			d2.NhapDiem();
			std::cout << "Nhap toa do cua diem 3:\n";
			d3.NhapDiem();
			std::cout << "Nhap toa do cua diem 4:\n";
			d4.NhapDiem();

			if ((d2.getX() - d1.getX()) == (d4.getX() - d3.getX()) && (d2.getY() - d1.getY()) == (d4.getY() - d3.getY())) {
				setDinh1(d1);
				setDinh2(d2);
				setDinh3(d3);
				setDinh4(d4);
				hopLe = true;
			}
			else {
				std::cout << "Nhap khong hop le. Hinh binh hanh khong thoa man dieu kien. Vui long nhap lai.\n";
			}
		} while (!hopLe);
	}
};

class HinhVuong : public TuGiac {
public:
    HinhVuong() : TuGiac() {
    }

    HinhVuong(Diem d1, Diem d2, Diem d3, Diem d4) : TuGiac(d1, d2, d3, d4) {
        if (!((d2.getY() - d1.getY() == 0 && d3.getY() - d4.getY() == 0) &&
              (d2.getX() - d1.getX() == d3.getX() - d4.getX()))) {
            Dinh1 = Diem();
            Dinh2 = Diem();
            Dinh3 = Diem();
            Dinh4 = Diem();
        }
    }

    void Nhap() {
        Diem d1, d2, d3, d4;
        bool hopLe = false;

        do {
            std::cout << "Nhap toa do cua diem 1:\n";
            d1.NhapDiem();
            std::cout << "Nhap toa do cua diem 2:\n";
            d2.NhapDiem();
            std::cout << "Nhap toa do cua diem 3:\n";
            d3.NhapDiem();
            std::cout << "Nhap toa do cua diem 4:\n";
            d4.NhapDiem();

            if ((d2.getY() - d1.getY() == 0 && d3.getY() - d4.getY() == 0) &&
                (d2.getX() - d1.getX() == d3.getX() - d4.getX())) {
                setDinh1(d1);
                setDinh2(d2);
                setDinh3(d3);
                setDinh4(d4);
                hopLe = true;
            } else {
                std::cout << "Nhap khong hop le. Hinh vuong khong thoa man dieu kien. Vui long nhap lai.\n";
            }
        } while (!hopLe);
    }
};
class HinhChuNhat : public TuGiac {
public:
	HinhChuNhat() : TuGiac() {}
	HinhChuNhat(Diem d1, Diem d2, Diem d3, Diem d4) : TuGiac(d1, d2, d3, d4) {
		if (!((d2.getY() - d1.getY() == d3.getY() - d4.getY()) &&
			(d2.getX() - d1.getX() == 0 && d3.getX() - d4.getX() == 0))) {
			Dinh1 = Diem();
			Dinh2 = Diem();
			Dinh3 = Diem();
			Dinh4 = Diem();
		}
	}
	void Nhap() {
		Diem d1, d2, d3, d4;
		bool hopLe = false;

		do {
			std::cout << "Nhap toa do cua diem 1:\n";
			d1.NhapDiem();
			std::cout << "Nhap toa do cua diem 2:\n";
			d2.NhapDiem();
			std::cout << "Nhap toa do cua diem 3:\n";
			d3.NhapDiem();
			std::cout << "Nhap toa do cua diem 4:\n";
			d4.NhapDiem();
			if ((d2.getY() - d1.getY() == d3.getY() - d4.getY()) &&
				(d2.getX() - d1.getX() == 0 && d3.getX() - d4.getX() == 0)) {
				setDinh1(d1);
				setDinh2(d2);
				setDinh3(d3);
				setDinh4(d4);
				hopLe = true;
			}
			else {
				std::cout << "Nhap khong hop le. Hinh chu nhat khong thoa man dieu kien. Vui long nhap lai.\n";
			}
		} while (!hopLe);
	}
};
int main() {
	TuGiac* hinh;
	int loai;
	std::cout << "Chon loai hinh can nhap: ";
	std::cout << "\n1. Hinh thang\n2. Hinh binh hanh\n3. Hinh vuong\n4. Hinh chu nhat\n ";
	std::cin >> loai;
	switch (loai)
	{
	case 1:
		hinh = new HinhThang;
		break;
	case 2:
		hinh = new HinhBinhHanh;
		break;
	case 3:
		hinh = new HinhVuong;
		break;
	case 4:
		hinh = new HinhChuNhat;
		break;
	default:
		hinh = new TuGiac;
		break;
	}
	hinh->Nhap();
	hinh->Xuat();
	return 0;
}