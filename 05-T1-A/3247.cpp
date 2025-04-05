#include <bits/stdc++.h>

constexpr int LIMITE = 1010;
constexpr int64_t MODULO = 2147483647;

int tamanho;
bool tabuleiro[LIMITE][LIMITE];
int64_t cache[LIMITE][LIMITE];
bool visitado[LIMITE][LIMITE] = {false};

const std::vector<std::pair<int, int>> movimentosDFS = {{1, 0}, {0, 1}};
const std::vector<std::pair<int, int>> movimentosBFS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool dentroDosLimites(int linha, int coluna) {
    return linha >= 0 && linha < tamanho && coluna >= 0 && coluna < tamanho;
}

int64_t contarCaminhos(int linha, int coluna) {
    if (!dentroDosLimites(linha, coluna) || !tabuleiro[linha][coluna]) return 0;
    if (linha == tamanho - 1 && coluna == tamanho - 1) return 1;

    int64_t& resultado = cache[linha][coluna];
    if (resultado != -1) return resultado;

    int64_t caminhos = 0;
    for (const auto& [dx, dy] : movimentosDFS) {
        caminhos = (caminhos + contarCaminhos(linha + dx, coluna + dy)) % MODULO;
    }

    return resultado = caminhos;
}

bool verificarAcesso() {
    std::queue<std::pair<int, int>> fila;
    fila.push({0, 0});
    visitado[0][0] = true;

    while (!fila.empty()) {
        auto [linha, coluna] = fila.front();
        fila.pop();

        if (linha == tamanho - 1 && coluna == tamanho - 1) {
            return true;
        }

        for (const auto& [dx, dy] : movimentosBFS) {
            int novaLinha = linha + dx;
            int novaColuna = coluna + dy;

            if (dentroDosLimites(novaLinha, novaColuna) && tabuleiro[novaLinha][novaColuna] && !visitado[novaLinha][novaColuna]) {
                visitado[novaLinha][novaColuna] = true;
                fila.push({novaLinha, novaColuna});
            }
        }
    }

    return false;
}

void executar() {
    std::cin >> tamanho;

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            char entrada;
            std::cin >> entrada;
            tabuleiro[i][j] = (entrada == '.');
        }
    }

    std::memset(cache, -1, sizeof(cache));
    int64_t resultado = contarCaminhos(0, 0);

    if (resultado > 0) {
        std::cout << resultado << '\n';
        return;
    }

    std::cout << (verificarAcesso() ? "THE GAME IS A LIE" : "INCONCEIVABLE") << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    executar();
    return 0;
}
