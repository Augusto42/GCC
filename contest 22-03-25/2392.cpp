#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> stones(N + 1, 0);
    
    for (int i = 0; i < M; ++i) {
        int P, D;
        cin >> P >> D;
        for (int j = P; j <= N; j += D) stones[j] = 1;
        for (int j = P; j >= 1; j -= D) stones[j] = 1;
    }
    
    for (int i = 1; i <= N; ++i) cout << stones[i] << "\n";
    
    return 0;
}
//Augusto C Fagundes