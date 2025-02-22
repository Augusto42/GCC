#include <iostream>

using namespace std;

int main() {
    int n, atual, anterior, cont = 1, maxCont = 1;
    cin >> n >> anterior;
    
    for (int i = 1; i < n; i++) {
        cin >> atual;
        if (atual == anterior) {
            cont++;
            maxCont = max(maxCont, cont);
        } else {
            cont = 1;
        }
        anterior = atual;
    }
    
    cout << maxCont << endl;
    return 0;
}

// Augusto C Fagundes
