#include <iostream>

using namespace std;

int main() {
    int Cv, Ce, Cs, Fv, Fe, Fs;
    cin >> Cv >> Ce >> Cs >> Fv >> Fe >> Fs;
    
    int pontosC = Cv * 3 + Ce;
    int pontosF = Fv * 3 + Fe;
    
    if (pontosC > pontosF) cout << "C" << endl;
    else if (pontosF > pontosC) cout << "F" << endl;
    else {
        if (Cs > Fs) cout << "C" << endl;
        else if (Fs > Cs) cout << "F" << endl;
        else cout << "=" << endl;
    }
    
    return 0;
}

// Augusto C Fagundes
