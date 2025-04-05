#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int64_t totalPessoas, totalRelacoes;
    std::cin >> totalRelacoes >> totalPessoas;

    std::unordered_map<std::string, int> nomeParaId;
    std::vector<std::vector<int>> grafo(317);
    std::vector<int> visitado(317, 0);
    int proximoId = 1;
    int componentes = 0;

    auto adicionarLigacao = [&](int a, int b) {
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    };

    auto buscaProfundidade = [&](int inicio, auto&& dfsRef) -> void {
        visitado[inicio] = 1;
        for (int vizinho : grafo[inicio]) {
            if (!visitado[vizinho]) {
                dfsRef(vizinho, dfsRef);
            }
        }
    };

    for (int i = 0; i < totalPessoas; ++i) {
        std::string nomeA, palavraDescartada, nomeB;
        std::cin >> nomeA >> palavraDescartada >> nomeB;

        if (nomeParaId.find(nomeA) == nomeParaId.end()) {
            nomeParaId[nomeA] = proximoId++;
        }
        if (nomeParaId.find(nomeB) == nomeParaId.end()) {
            nomeParaId[nomeB] = proximoId++;
        }

        adicionarLigacao(nomeParaId[nomeA], nomeParaId[nomeB]);
    }

    for (int i = 1; i <= totalRelacoes; ++i) {
        if (!visitado[i]) {
            buscaProfundidade(i, buscaProfundidade);
            ++componentes;
        }
    }

    std::cout << componentes << '\n';
    return 0;
}
