#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;
    int components;
public:
    UnionFind(int n) : parent(n + 1), rank(n + 1, 0), components(n) {
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (parent[u] != u) parent[u] = find(parent[u]);
        return parent[u];
    }
    
    void unite(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            components--;
        }
    }
    
    int count() {
        return components;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }
    
    cout << uf.count() << "\n";
    return 0;
}
//Augusto C Fagundes