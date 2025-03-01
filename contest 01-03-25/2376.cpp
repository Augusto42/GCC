#include <iostream>
#include <vector>

using namespace std;

vector<char> equipes = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};

int main() {
    vector<char> vencedores = equipes;
    int jogo = 1;
    
    while (vencedores.size() > 1) {
        vector<char> proximos;
        
        for (size_t i = 0; i < vencedores.size(); i += 2) {
            int M, N;
            cin >> M >> N;
            
            if (M > N) {
                proximos.push_back(vencedores[i]);
            } else {
                proximos.push_back(vencedores[i + 1]);
            }
            
            jogo++;
        }
        
        vencedores = proximos;
    }
    
    cout << vencedores[0] << endl;
    
    return 0;
}

//Augusto C Fagundes