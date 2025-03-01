#include <iostream>

using namespace std;

int main() {
    int A, N;
    cin >> A >> N;
    
    int visiveis = 0;
    const int LIMIAR = 40000000;
    
    for (int i = 0; i < N; i++) {
        int F;
        cin >> F;
        if (A * F >= LIMIAR) {
            visiveis++;
        }
    }
    
    cout << visiveis << endl;
    
    return 0;
}

//Augusto C Fagundes