#include <iostream>
using namespace std;

int main() {
    int N, S;
    cin >> N >> S;
    int minSaldo = S;
    
    for (int i = 0; i < N; i++) {
        int movimentacao;
        cin >> movimentacao;
        S += movimentacao;
        if (S < minSaldo) {
            minSaldo = S;
        }
    }
    
    cout << minSaldo << "\n";
    return 0;
}
//Augusto C Fagundes