#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    string nome;
    int num;
    int prev, next;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        
        vector<Node> circulo(n);
        for (int i = 0; i < n; i++){
            cin >> circulo[i].nome >> circulo[i].num;
        }
        for (int i = 0; i < n; i++){
            circulo[i].prev = (i - 1 + n) % n;
            circulo[i].next = (i + 1) % n;
        }
        
        int current = 0;
        int restantes = n;
        int passos = circulo[current].num;
        
        while(restantes > 1){
            int mover = passos % restantes;
            if(mover == 0) mover = restantes;
            
            if(passos % 2 == 1){
                for (int i = 0; i < mover; i++){
                    current = circulo[current].next;
                }
            } else {
                for (int i = 0; i < mover; i++){
                    current = circulo[current].prev;
                }
            }
            passos = circulo[current].num;
            
            int p = circulo[current].prev;
            int nIndex = circulo[current].next;
            circulo[p].next = nIndex;
            circulo[nIndex].prev = p;
            restantes--;
        }
        int vencedor = circulo[current].next;
        cout << "Vencedor(a): " << circulo[vencedor].nome << "\n";
    }
    return 0;
}
// Augusto C Fagundes