#include <iostream>

using namespace std;

int main() {
    int V, T;
    cin >> V >> T;

    for (int i = 0; i < T; i++) {
        int A;
        cin >> A;
        V += A;
        if (V > 100) V = 100;
        if (V < 0) V = 0;
    }

    cout << V << "\n";
    return 0;
}
//Augusto C Fagundes