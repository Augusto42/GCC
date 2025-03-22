#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<tuple<int, int, int>> hints;
    
    for (int i = 0; i < K; ++i) {
        int X, Y, D;
        cin >> X >> Y >> D;
        hints.emplace_back(X, Y, D);
    }
    
    int possibleX = -1, possibleY = -1, count = 0;
    
    for (int tx = 0; tx < N; ++tx) {
        for (int ty = 0; ty < N; ++ty) {
            bool valid = true;
            for (const auto& hint : hints) {
                int hx, hy, d;
                tie(hx, hy, d) = hint;
                if (abs(hx - tx) + abs(hy - ty) != d) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                if (count == 0) {
                    possibleX = tx;
                    possibleY = ty;
                } else {
                    cout << "-1 -1\n";
                    return 0;
                }
                count++;
            }
        }
    }
    
    cout << possibleX << " " << possibleY << "\n";
    return 0;
}
//Augusto C Fagundes