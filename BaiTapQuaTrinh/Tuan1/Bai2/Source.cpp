#include <iostream>
using namespace std;

struct Fraction {
	int Numerator;
	int Denominator;
};

void Input(Fraction&);
void Print(Fraction);
Fraction Max_Fraction(Fraction, Fraction);

int main() {
	Fraction fraction1,fraction2;
	Input(fraction1);
	Input(fraction2);
	cout << "Largest fraction of two fractions: ";
	Print(Max_Fraction(fraction1, fraction2));
	return 0;
}

void Input(Fraction& fraction) {
	cout << "Numerator: ";
	cin >> fraction.Numerator;
	cout << "Denominator: ";
	cin >> fraction.Denominator;
}
void Print(Fraction fraction) {
	cout << fraction.Numerator << "/" << fraction.Denominator;
}
Fraction Max_Fraction(Fraction a,Fraction b) {
	return float(a.Numerator) / a.Denominator > float(b.Numerator) / b.Denominator ? a : b;
}