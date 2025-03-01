#include <iostream>

using namespace std;

int main() {
    int N, A, L, P;
    cin >> N >> A >> L >> P;
    
    if (N <= A && N <= L && N <= P) {
        cout << 'S' << endl;
    } else {
        cout << 'N' << endl;
    }
    
    return 0;
}

//Augusto C Fagundes