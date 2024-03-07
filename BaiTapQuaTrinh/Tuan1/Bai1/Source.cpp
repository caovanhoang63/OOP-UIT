#include <iostream>
using namespace std;

struct Fraction {
	int Numerator;
	int Denominator;
};


int GCD(int , int );
void Input(Fraction&);
void Print(Fraction);
void ReduceFraction(Fraction&);

int main() {
	Fraction fraction;
	Input(fraction);
	ReduceFraction(fraction);
	cout << "After reduce"<< endl;
	Print(fraction);
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
