#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string L, N, S;
    getline(cin, L);
    getline(cin, N);
    getline(cin, S);
    
    vector<string> friends;
    istringstream ls(L);
    string name;
    while (ls >> name) {
        friends.push_back(name);
    }
    
    vector<string> new_friends;
    istringstream ns(N);
    while (ns >> name) {
        new_friends.push_back(name);
    }
    
    auto it = find(friends.begin(), friends.end(), S);
    if (S == "nao" || it == friends.end()) {
        friends.insert(friends.end(), new_friends.begin(), new_friends.end());
    } else {
        friends.insert(it, new_friends.begin(), new_friends.end());
    }
    
    for (size_t i = 0; i < friends.size(); ++i) {
        if (i > 0) cout << " ";
        cout << friends[i];
    }
    cout << "\n";
    
    return 0;
}
// Augusto C Fagundes