#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    unordered_set<string> jewels;
    string jewel;
    while (cin >> jewel) {
        jewels.insert(jewel);
    }
    cout << jewels.size() << "\n";
    return 0;
}
//Augusto C Fagundes