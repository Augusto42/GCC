#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string equation;
    while (getline(cin, equation)) {
        size_t plus = equation.find('+');
        size_t equal = equation.find('=');

        string R = equation.substr(0, plus);
        string L = equation.substr(plus + 1, equal - plus - 1);
        string J = equation.substr(equal + 1);

        int r = -1, l = -1, j = -1;
        if (R.find('R') == string::npos) r = stoi(R);
        if (L.find('L') == string::npos) l = stoi(L);
        if (J.find('J') == string::npos) j = stoi(J);

        if (r == -1) cout << j - l << "\n";
        else if (l == -1) cout << j - r << "\n";
        else cout << r + l << "\n";
    }
    return 0;
}

//Augusto C Fagundes