#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int total = 7; 
    
    if (N > 10) {
        int restante = N - 10;
        
        if (restante > 0) {
            int faixa = min(restante, 20);
            total += faixa * 1;
            restante -= faixa;
        }
        
        if (restante > 0) {
            int faixa = min(restante, 70);
            total += faixa * 2;
            restante -= faixa;
        }
        
        if (restante > 0) {
            total += restante * 5;
        }
    }
    
    cout << total << endl;
    
    return 0;
}

//Augusto C Fagundes