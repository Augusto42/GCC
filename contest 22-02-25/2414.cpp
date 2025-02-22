#include <iostream>

using namespace std;

int main() {
    int n, maior = 0;
    while (cin >> n && n != 0) {
        if (n > maior) {
            maior = n;
        }
    }
    cout << maior << endl;
    return 0;
}

// Augusto C Fagundes
