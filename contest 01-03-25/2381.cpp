#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<string> alunos(N);
    
    for (int i = 0; i < N; i++) {
        cin >> alunos[i];
    }
    
    sort(alunos.begin(), alunos.end());
    
    cout << alunos[K - 1] << endl;
    
    return 0;
}

//Augusto C Fagundes