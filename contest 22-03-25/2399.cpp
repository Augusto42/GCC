#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> board(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }
    
    for (int i = 0; i < N; ++i) {
        int mines = board[i];
        if (i > 0) mines += board[i - 1];
        if (i < N - 1) mines += board[i + 1];
        cout << mines << "\n";
    }
    
    return 0;
}
//Augusto C Fagundes