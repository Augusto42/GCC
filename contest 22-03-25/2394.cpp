#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int winner = 1, min_time = 1e9;
    
    for (int i = 1; i <= N; ++i) {
        int total_time = 0, time;
        for (int j = 0; j < M; ++j) {
            cin >> time;
            total_time += time;
        }
        if (total_time < min_time) {
            min_time = total_time;
            winner = i;
        }
    }
    
    cout << winner << "\n";
    return 0;
}
//Augusto C Fagundes