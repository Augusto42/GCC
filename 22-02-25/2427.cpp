#include <iostream>

using namespace std;

int main() {
    int L, total = 1;
    cin >> L;
    
    while (L >= 2) {
        total *= 4;
        L /= 2;
    }
    
    cout << total << endl;
    return 0;
}

// Augusto C Fagundes
