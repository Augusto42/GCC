#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int L, A, P, R;
    cin >> L >> A >> P >> R;
    
    double diagonal = sqrt(L * L + A * A + P * P);
    
    if (diagonal <= 2 * R) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    
    return 0;
}

//Augusto C Fagundes