#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES
# define M_PI           3.141592
using namespace std;

class Shape {
public:
	virtual double getArea() const = 0;
	virtual void enter() = 0;
	virtual void print() const = 0;
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(double r) : radius(r) {}

	double getRadius() const {
		return radius;
	}

	void setRadius(double r) {
		radius = r;
	}

	double getArea() const override {
		return M_PI * radius * radius;
	}

	Circle(const Circle& other) {
		radius = other.radius;
	}

	Circle& operator=(const Circle& other) {
		if (this != &other) {
			radius = other.radius;
		}
		return *this;
	}

	Circle() : radius(0) {}

	void enter() override {
		double r;
		cout << "Enter the radius: ";
		cin >> r;
		setRadius(r);
	}

	void print() const override {
		cout << "Circle with radius " << getRadius() << ", area = " << getArea() << endl;
	}
};

class Ellipse : public Shape {
private:
	double a, b; // a: major axis, b: minor axis

public:
	Ellipse(double aa, double bb) : a(aa), b(bb) {}

	double getA() const {
		return a;
	}

	void setA(double aa) {
		a = aa;
	}

	double getB() const {
		return b;
	}

	void setB(double bb) {
		b = bb;
	}

	double getArea() const override {
		return M_PI * a * b;
	}

	Ellipse(const Ellipse& other) {
		a = other.a;
		b = other.b;
	}

	Ellipse& operator=(const Ellipse& other) {
		if (this != &other) {
			a = other.a;
			b = other.b;
		}
		return *this;
	}

	Ellipse() : a(0), b(0) {}

	void enter() override {
		double aa, bb;
		cout << "Enter the major axis: ";
		cin >> aa;
		cout << "Enter the minor axis: ";
		cin >> bb;
		setA(aa);
		setB(bb);
	}

	void print() const override {
		cout << "Ellipse with major axis " << getA() << ", minor axis " << getB() << ", area = " << getArea() << endl;
	}
};

int main() {
	int n;
	cout << "Enter the number of circles and ellipses: ";
	cin >> n;

	vector<Shape*> shapes;
	for (int i = 0; i < n; i++) {
		char c;

		cout << "Enter shape " << i + 1 << " (C - Circle, E - Ellipse): ";
		cin >> c;

		if (c == 'C' || c == 'c') {
			Circle* circle = new Circle(0);
			circle->enter();
			shapes.push_back(circle);
		}
		else if (c == 'E' || c == 'e') {
			Ellipse* ellipse = new Ellipse(0, 0);
			ellipse->enter();
			shapes.push_back(ellipse);
		}
		else {
			cout << "Invalid shape!\n";
			i--;
		}
	}
	for (Shape* shape : shapes) {
		delete shape;
	}

	return 0;
}

