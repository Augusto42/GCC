#include <iostream>
using namespace std;

int main() {
    int N1, D1, V1, N2, D2, V2;
    cin >> N1 >> D1 >> V1;
    cin >> N2 >> D2 >> V2;
    
    double T1 = static_cast<double>(D1) / V1;
    double T2 = static_cast<double>(D2) / V2;
    
    cout << (T1 < T2 ? N1 : N2) << "\n";
    
    return 0;
}
//Augusto C Fagundes