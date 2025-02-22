#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    int totalSum = 0, leftSum = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        totalSum += a[i];
    }
    
    for (int k = 0; k < N; k++) {
        leftSum += a[k];
        if (leftSum * 2 == totalSum) {
            cout << k + 1 << endl;
            break;
        }
    }
    
    return 0;
}

// Augusto C Fagundes