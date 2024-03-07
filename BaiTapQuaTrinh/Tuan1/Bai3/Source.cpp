#include <iostream>
using namespace std;

struct Fraction {
	int Numerator;
	int Denominator;
};

void Input(Fraction&);
void Print(Fraction);
Fraction Sum(Fraction,Fraction );
Fraction Sub(Fraction,Fraction);
Fraction Mul(Fraction,Fraction);
Fraction Div(Fraction,Fraction);
int GCD(int, int);
void ReduceFraction(Fraction&);

int main() {
	Fraction fraction1, fraction2;
	Input(fraction1);
	Input(fraction2);
	cout << "Sum of two fractions: ";
	Print(Sum(fraction1, fraction2));
	cout << "\nDifferent of two fractions: ";
	Print(Sub(fraction1, fraction2));
	cout << "\nProduct of two fractions: ";
	Print(Mul(fraction1, fraction2));
	cout << "\nQuotient of two fractions: ";
	Print(Div(fraction1,fraction2));
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
int GCD(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}
void ReduceFraction(Fraction& fraction) {
	int temp = GCD(abs(fraction.Numerator), abs(fraction.Denominator));
	if (fraction.Numerator < 0 && fraction.Denominator < 0)
		temp = -temp;
	fraction.Numerator /= temp;
	fraction.Denominator /= temp;
}
Fraction Sum(Fraction a, Fraction b) {
	Fraction sum;
	sum.Numerator = a.Numerator * b.Denominator + b.Numerator * a.Denominator;
	sum.Denominator = a.Denominator * b.Denominator;
	ReduceFraction(sum);
	return sum;
}
Fraction Sub(Fraction a, Fraction b) {
	Fraction sub;
	sub.Numerator = a.Numerator * b.Denominator - b.Numerator * a.Denominator;
	sub.Denominator = a.Denominator * b.Denominator;
	ReduceFraction(sub);
	return sub;
}
Fraction Mul(Fraction a, Fraction b) {
	Fraction mul;
	mul.Numerator = a.Numerator * b.Numerator;
	mul.Denominator = a.Denominator * b.Denominator;
	ReduceFraction(mul);
	return mul;
}
Fraction Div(Fraction a, Fraction b) {
	Fraction div ;
	div.Numerator = a.Numerator *b.Denominator;
	div.Denominator = a.Denominator * b.Numerator;
	ReduceFraction(div);
	return div;
}