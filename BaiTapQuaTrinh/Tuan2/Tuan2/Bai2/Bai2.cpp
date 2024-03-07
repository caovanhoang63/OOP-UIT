#include <iostream>
using namespace std;

struct ComplexNumber {
	float real;
	float imag;
};

istream& operator>>(istream& is, ComplexNumber &a) {
	cout << "Real: ";
	is >> a.real;
	cout << "Imagine: ";
	is >> a.imag;
	return is;
}
ostream& operator<<(ostream& os, ComplexNumber a) {
	float temp ;
	if (a.imag > 0) {
		os << a.real << "+" << a.imag << "i";
	}
	else if (a.imag < 0) {
		os << a.real <<(a.imag) << "i";
	}
	else {
		os << a.real ;
	}
	return os;
}

ComplexNumber operator+(ComplexNumber a, ComplexNumber b) {
	ComplexNumber temp;
	temp.real = a.real + b.real ;
	temp.imag = a.imag + b.imag;
	return (temp);
}
ComplexNumber operator-(ComplexNumber a, ComplexNumber b) {
	ComplexNumber temp;
	temp.real = a.real  - b.real ;
	temp.imag = a.imag  - b.imag;
	return (temp);
}
ComplexNumber operator*(ComplexNumber a, ComplexNumber b) {
	ComplexNumber temp;
	temp.real = a.real * b.real - a.imag*b.imag;
	temp.imag = a.real * b.imag + b.real * a.imag;
	return (temp);
}
ComplexNumber operator/(ComplexNumber a, ComplexNumber b) {
	ComplexNumber temp;
	temp.real = (a.real * b.real + a.imag * b.imag) / (b.real*b.real + b.imag * b.imag);
	temp.imag = (b.real * a.imag - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
	return (temp);
}
int main() {
	ComplexNumber a, b;
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << a / b << endl;
	return 0;
}