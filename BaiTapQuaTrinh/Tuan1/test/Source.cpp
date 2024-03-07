#include <iostream>
#include <vector>
using namespace std;
struct Fraction {
    int Numerator;
    int Denominator;
};

void Input(Fraction&);
void Print(Fraction);
void Sort(vector<Fraction> vt, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
        {
            if ((float(vt[i].Numerator) / vt[i].Denominator) > (float(vt[j].Numerator) / vt[j].Denominator)) {
                Fraction temp;
                temp = vt[i];
                vt[i] = vt[j];
                vt[j] = temp;
            }
        }
    }
}
void Result(vector<Fraction> vt, int n, int k) {
    if (k > n)
        return;
    Print(vt[n - k]);
    cout << endl;
    Print(vt[k - 1]);
}
int main() {
    vector <Fraction>vt;
    int n, k;
    cin >> n;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        Fraction fraction;
        Input(fraction);
        vt.push_back(fraction);
    }
    Sort(vt, n);
    Result(vt, n, k);
    return 0;
}

void Input(Fraction& fraction) {
    cin >> fraction.Numerator;
    while (true)
    {
        cin >> fraction.Denominator;
        if (fraction.Denominator == 0) {
            continue;
        }
        break;
    }
}
void Print(Fraction fraction) {
    cout << fraction.Numerator << "/" << fraction.Denominator;
}

