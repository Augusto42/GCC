#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<bool>> grid(101, vector<bool>(101, false));
    
    for (int i = 0; i < N; ++i) {
        int Xi, Xf, Yi, Yf;
        cin >> Xi >> Xf >> Yi >> Yf;
        for (int x = Xi; x < Xf; ++x) {
            for (int y = Yi; y < Yf; ++y) {
                grid[x][y] = true;
            }
        }
    }
    
    int area = 0;
    for (int x = 1; x <= 100; ++x) {
        for (int y = 1; y <= 100; ++y) {
            if (grid[x][y]) area++;
        }
    }
    
    cout << area << "\n";
    return 0;
}

//Augusto C Fagundes