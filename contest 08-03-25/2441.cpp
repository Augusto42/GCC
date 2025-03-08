#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int F[3];
    for (int i = 0; i < 3; i++) cin >> F[i];

    bool janela[600] = {false};

    for (int i = 0; i < 3; i++) {
        for (int j = F[i]; j < F[i] + 200; j++) {
            janela[j] = true;
        }
    }

    int aberto = 0;
    for (int i = 0; i < 600; i++) {
        if (!janela[i]) aberto++;
    }

    cout << aberto * 100 << "\n";
    return 0;
}
//Augusto C Fagundes