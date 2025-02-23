#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<string> telefones(n);
        for (int i = 0; i < n; i++) {
            cin >> telefones[i];
        }
        // Ordena os números de telefone em ordem lexicográfica
        sort(telefones.begin(), telefones.end());
        
        int totalPrefixos = 0;
        // Compara cada par consecutivo de telefones
        for (int i = 1; i < n; i++) {
            int cont = 0;
            // Percorre os dígitos enquanto forem iguais
            for (size_t j = 0; j < telefones[i].size() && j < telefones[i-1].size(); j++) {
                if (telefones[i][j] == telefones[i-1][j])
                    cont++;
                else
                    break;
            }
            totalPrefixos += cont;
        }
        cout << totalPrefixos << "\n";
    }
    return 0;
    //Augusto C Fagundes
}