#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> valores(3);
    cin >> valores[0] >> valores[1] >> valores[2];
    sort(valores.begin(), valores.end(), greater<int>());
    cout << valores[1] << endl;
    return 0;
}

// Augusto C Fagundes