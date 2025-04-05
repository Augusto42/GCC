#include <bits/stdc++.h>

int64_t linhas, colunas;
char grade[52][52];
bool visitado[52][52];

const std::vector<std::pair<int64_t, int64_t>> direcoes = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool podeAcessar(int64_t x, int64_t y) {
    return x >= 0 && x < linhas && y >= 0 && y < colunas &&
           !visitado[x][y] && grade[x][y] != 'X';
}

void espalharFogo(std::queue<std::pair<int64_t, int64_t>>& fila) {
    while (!fila.empty()) {
        auto atual = fila.front();
        fila.pop();

        int64_t x = atual.first;
        int64_t y = atual.second;

        visitado[x][y] = true;

        for (const auto& dir : direcoes) {
            int64_t novoX = x + dir.first;
            int64_t novoY = y + dir.second;

            if (podeAcessar(novoX, novoY)) {
                fila.push({novoX, novoY});
                visitado[novoX][novoY] = true;
                grade[novoX][novoY] = 'T';
            }
        }
    }
}

void resolver() {
    std::queue<std::pair<int64_t, int64_t>> inicio;

    for (int64_t i = 0; i < linhas; ++i) {
        for (int64_t j = 0; j < colunas; ++j) {
            char entrada;
            std::cin >> entrada;
            grade[i][j] = entrada;
            if (entrada == 'T') {
                inicio.push({i, j});
            }
        }
    }

    std::memset(visitado, 0, sizeof(visitado));
    espalharFogo(inicio);

    for (int64_t i = 0; i < linhas; ++i) {
        for (int64_t j = 0; j < colunas; ++j) {
            std::cout << grade[i][j];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (std::cin >> linhas >> colunas) {
        if (linhas == 0 && colunas == 0) break;
        resolver();
    }

    return 0;
}
