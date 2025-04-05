#include <bits/stdc++.h>

class DisjointSet {
private:
    std::vector<int64_t> parent;
    std::vector<int64_t> size;
    int64_t components;

public:
    DisjointSet(int64_t n) : parent(n), size(n, 1), components(n) {
        for (int64_t i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int64_t find(int64_t node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    void unite(int64_t a, int64_t b) {
        int64_t rootA = find(a);
        int64_t rootB = find(b);
        if (rootA == rootB) return;
        if (size[rootA] > size[rootB]) std::swap(rootA, rootB);
        parent[rootA] = rootB;
        size[rootB] += size[rootA];
        --components;
    }

    int64_t getComponents() const {
        return components;
    }

    int64_t getRootSize(int64_t node) {
        return size[find(node)];
    }

    int64_t getRoot(int64_t node) {
        return find(node);
    }
};

void analisarCombinacoes(int64_t totalTorres, int64_t totalConexoes) {
    std::vector<char> tipos(totalTorres);
    for (int64_t i = 0; i < totalTorres; ++i) {
        std::cin >> tipos[i];
    }

    DisjointSet conjunto(totalTorres);

    for (int64_t i = 0; i < totalConexoes; ++i) {
        int64_t origem, destino;
        std::cin >> origem >> destino;
        conjunto.unite(origem - 1, destino - 1);
    }

    std::vector<int64_t> contagemB(totalTorres, 0);

    for (int64_t i = 0; i < totalTorres; ++i) {
        if (tipos[i] == 'B') {
            contagemB[conjunto.getRoot(i)]++;
        }
    }

    bool valido = true;

    for (int64_t i = 0; i < totalTorres; ++i) {
        if (conjunto.getRoot(i) == i && contagemB[i] % 2 != 0) {
            valido = false;
            break;
        }
    }

    std::cout << (valido ? "Y" : "N") << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t torres, conexoes;
    while (std::cin >> torres >> conexoes) {
        analisarCombinacoes(torres, conexoes);
    }

    return 0;
}
