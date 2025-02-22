#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<double> notas(5);
    for (int i = 0; i < 5; i++) {
        cin >> notas[i];
    }
    
    sort(notas.begin(), notas.end());
    double soma = notas[1] + notas[2] + notas[3];
    
    cout << fixed;
    cout.precision(1);
    cout << soma << endl;
    
    return 0;
}

// Augusto C Fagundes