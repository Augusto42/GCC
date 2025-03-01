#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<vector<int>> floydWarshall(int n, vector<vector<int>> &dist) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> dist(N, vector<int>(N, INF));
    
    for (int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        int U, V, W;
        cin >> U >> V >> W;
        dist[U][V] = min(dist[U][V], W);
        dist[V][U] = min(dist[V][U], W);
    }
    
    dist = floydWarshall(N, dist);
    
    int menorMaxDist = INF;
    
    for (int i = 0; i < N; i++) {
        int maxDist = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) {
                maxDist = max(maxDist, dist[i][j]);
            }
        }
        menorMaxDist = min(menorMaxDist, maxDist);
    }
    
    cout << menorMaxDist << endl;
    
    return 0;
}

//Augusto C Fagundes