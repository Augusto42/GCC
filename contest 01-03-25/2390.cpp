#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int tempoTotal = 0, ultimoAtivado = -10;
    
    for (int i = 0; i < N; i++) {
        int T;
        cin >> T;
        
        if (T >= ultimoAtivado + 10) {
            tempoTotal += 10;
        } else {
            tempoTotal += T - ultimoAtivado;
        }
        
        ultimoAtivado = T;
    }
    
    cout << tempoTotal << endl;
    
    return 0;
}

//Augusto C Fagundes