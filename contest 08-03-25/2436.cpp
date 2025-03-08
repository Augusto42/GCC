#include <iostream>
#include <vector>

using namespace std;

int L, C, A, B;
vector<vector<int>> grid;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < L && y >= 0 && y < C && grid[x][y] == 1;
}

pair<int, int> findFinalPosition(int x, int y) {
    while (true) {
        pair<int, int> nextPos = {-1, -1};
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                nextPos = {nx, ny};
                grid[x][y] = 0;
                x = nx;
                y = ny;
                break;
            }
        }
        if (nextPos.first == -1) break;
    }
    return {x + 1, y + 1};
}

int main() {
    cin >> L >> C >> A >> B;
    A--; B--;
    grid.assign(L, vector<int>(C));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }
    pair<int, int> result = findFinalPosition(A, B);
    cout << result.first << " " << result.second << "\n";
    return 0;
}
//Augusto C Fagundes