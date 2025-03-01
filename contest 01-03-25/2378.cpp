#include <iostream>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    
    int ocupacao = 0;
    bool excedeu = false;
    
    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        
        ocupacao -= S;
        ocupacao += E;
        
        if (ocupacao > C) {
            excedeu = true;
        }
    }
    
    cout << (excedeu ? 'S' : 'N') << endl;
    
    return 0;
}

//Augusto C Fagundes