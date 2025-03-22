#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> results;
    
    for (int i = 1; i <= N; ++i) {
        int total_time = 0, time;
        for (int j = 0; j < M; ++j) {
            cin >> time;
            total_time += time;
        }
        results.push_back({total_time, i});
    }
    
    sort(results.begin(), results.end());
    
    cout << results[0].second << "\n";
    cout << results[1].second << "\n";
    cout << results[2].second << "\n";
    
    return 0;
}
//Augusto C Fagundes    