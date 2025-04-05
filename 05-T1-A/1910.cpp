#include <bits/stdc++.h>

const int64_t LIMITE = 100001;

bool visitado[LIMITE];
bool bloqueado[LIMITE];
int64_t distancia[LIMITE];

void buscaLargura(int64_t inicio, int64_t alvo) {
    std::queue<int64_t> fila;
    fila.push(inicio);
    visitado[inicio] = true;
    distancia[inicio] = 0;

    while (!fila.empty()) {
        int64_t atual = fila.front();
        fila.pop();

        if (atual == alvo) return;

        std::vector<int64_t> proximos = {atual + 1, atual - 1, atual * 2, atual * 3};
        if (atual % 2 == 0) {
            proximos.push_back(atual / 2);
        }

        for (int64_t vizinho : proximos) {
            if (vizinho < 1 || vizinho >= LIMITE) continue;
            if (bloqueado[vizinho]) continue;
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                distancia[vizinho] = distancia[atual] + 1;
                fila.push(vizinho);
            }
        }
    }
}

void resolverInstancia(int64_t origem, int64_t destino, int64_t quantidadeBloqueados) {
    for (int64_t i = 0; i < LIMITE; ++i) {
        visitado[i] = false;
        distancia[i] = -1;
        bloqueado[i] = false;
    }

    for (int64_t i = 0; i < quantidadeBloqueados; ++i) {
        int64_t canal;
        std::cin >> canal;
        if (canal >= 1 && canal < LIMITE) {
            bloqueado[canal] = true;
        }
    }

    buscaLargura(origem, destino);
    std::cout << distancia[destino] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t origem, destino, bloqueios;

    while (std::cin >> origem >> destino >> bloqueios) {
        if (origem == 0 && destino == 0 && bloqueios == 0) break;
        resolverInstancia(origem, destino, bloqueios);
    }

    return 0;
}
