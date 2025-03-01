#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int distancia_total = 0;
    
    for (int i = 0; i < N; i++) {
        int T, V;
        cin >> T >> V;
        distancia_total += T * V;
    }
    
    cout << distancia_total << endl;
    
    return 0;
}

//Augusto C Fagundes