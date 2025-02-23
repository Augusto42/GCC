#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N && N != 0) {
        while (true) {
            vector<int> target(N);
            cin >> target[0];
            if (target[0] == 0) break;
            for (int i = 1; i < N; i++) cin >> target[i];
            
            stack<int> station;
            int current = 1, index = 0;
            
            while (current <= N || !station.empty()) {
                if (!station.empty() && station.top() == target[index]) {
                    station.pop();
                    index++;
                } else if (current <= N) {
                    station.push(current);
                    current++;
                } else {
                    break;
                }
            }
            
            cout << (index == N ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
    return 0;
}

// Augusto C Fagundes
