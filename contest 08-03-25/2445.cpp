#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> palitos(N);
    for (int i = 0; i < N; i++) cin >> palitos[i];

    sort(palitos.begin(), palitos.end());

    long long soma = 0;
    int usados = N;

    for (int i = 0; i < N - 1; i++) soma += palitos[i];

    while (usados >= 3 && palitos[usados - 1] >= soma) {
        usados--;
        soma -= palitos[usados - 1];
    }

    cout << (usados >= 3 ? usados : 0) << "\n";
    return 0;
}

//Augusto C Fagundes