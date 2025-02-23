#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    cin.ignore(); 
    
    bool firstCase = true;
    while (N--) {
        map<string, int> treeCount;
        int totalTrees = 0;
        string tree;
        
        while (getline(cin, tree) && !tree.empty()) {
            treeCount[tree]++;
            totalTrees++;
        }
        
        if (!firstCase) cout << endl;
        firstCase = false;
        
        for (const auto &entry : treeCount) {
            cout << entry.first << " " << fixed << setprecision(4) 
                 << (entry.second * 100.0 / totalTrees) << endl;
        }
    }
    return 0;
}

// Augusto C Fagundes
