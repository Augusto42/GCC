#include <iostream>

using namespace std;

int main() {
    int N, totalQuebrados = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int L, C;
        cin >> L >> C;
        if (L > C) {
            totalQuebrados += C;
        }
    }
    
    cout << totalQuebrados << endl;
    
    return 0;
}

//Augusto C Fagundes