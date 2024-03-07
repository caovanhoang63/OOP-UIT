#include <iostream>
using namespace std;

struct   Fraction{
	int Numerator;
	int Denominator;
};
int GCD(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
Fraction ReduceFraction(Fraction& fraction) {
	int temp = GCD(abs(fraction.Numerator), abs(fraction.Denominator));
	if (fraction.Numerator < 0 && fraction.Denominator < 0)
		temp = -temp;
	fraction.Numerator /= temp;
	fraction.Denominator /= temp;
	return fraction;
}
istream& operator>>(istream& is, Fraction &fraction) {
	cout << "Numerator: ";
	is >> fraction.Numerator;
	cout << "Denominator: ";
	is >> fraction.Denominator;
	return is;
}
ostream& operator<<(ostream& os, Fraction fraction) {
	os << fraction.Numerator << "/" << fraction.Denominator;
	return os;
}
Fraction operator+(Fraction fraction1, Fraction fraction2) {
	Fraction temp;
	temp.Numerator = fraction1.Numerator * fraction2.Denominator + fraction2.Numerator * fraction1.Denominator;
	temp.Denominator = fraction1.Denominator * fraction2.Denominator;
	return ReduceFraction(temp);
}
Fraction operator-(Fraction fraction1, Fraction fraction2) {
	Fraction temp;
	temp.Numerator = fraction1.Numerator * fraction2.Denominator - fraction2.Numerator * fraction1.Denominator;
	temp.Denominator = fraction1.Denominator * fraction2.Denominator;
	return ReduceFraction(temp);
}
Fraction operator*(Fraction fraction1, Fraction fraction2) {
	Fraction temp;
	temp.Numerator = fraction1.Numerator * fraction2.Numerator;
	temp.Denominator = fraction1.Denominator * fraction2.Denominator;
	return ReduceFraction(temp);
}
Fraction operator/(Fraction fraction1, Fraction fraction2) {
	Fraction temp;
	temp.Numerator = fraction1.Numerator * fraction2.Denominator;
	temp.Denominator = fraction1.Denominator * fraction2.Numerator;
	return ReduceFraction(temp);
}

int main() {
	Fraction a, b;
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b<<endl;
	cout << a << " - " << b << " = " << a - b<<endl;
	cout << a << " * " << b << " = " << a * b<<endl;
	cout << a << " / " << b << " = " << a / b;
	return 0;
}