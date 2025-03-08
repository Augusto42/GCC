#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int Xm, Ym, Xr, Yr;
    cin >> Xm >> Ym >> Xr >> Yr;
    cout << abs(Xm - Xr) + abs(Ym - Yr) << "\n";
    return 0;
}
//Augusto C Fagundes