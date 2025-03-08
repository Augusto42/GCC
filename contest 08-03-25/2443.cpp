#include <iostream>
#include <numeric>

using namespace std;

int mdc(int a, int b) {
    return b == 0 ? a : mdc(b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int num = a * d + c * b;
    int den = b * d;

    int gcd = __gcd(num, den);

    cout << num / gcd << " " << den / gcd << "\n";
    return 0;
}
//Augusto C Fagundes