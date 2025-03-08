#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;
//WRONG ANSWER 80%
struct Trie {
    map<string, Trie*> children;
};

void insert(Trie* root, const vector<string>& path) {
    Trie* node = root;
    for (const string& dir : path) {
        if (!node->children.count(dir)) {
            node->children[dir] = new Trie();
        }
        node = node->children[dir];
    }
}

int totalLength(Trie* node, int depth) {
    if (node->children.empty()) return 0;
    int length = 0;
    for (auto& child : node->children) {
        length += totalLength(child.second, depth + 1) + child.first.size() + 1;
    }
    return length;
}

void findBestReference(Trie* node, int depth, int total, int& minLength, int up) {
    if (node->children.empty()) return;
    int currentLength = total - depth * up;
    minLength = min(minLength, currentLength);
    for (auto& child : node->children) {
        findBestReference(child.second, depth + 1, total, minLength, up + 1);
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore();
    Trie* root = new Trie();
    vector<string> paths;
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        paths.push_back(line);
        vector<string> path;
        stringstream ss(line);
        string segment;
        while (getline(ss, segment, '/')) {
            path.push_back(segment);
        }
        insert(root, path);
    }
    int total = totalLength(root, 0);
    int minLength = total;
    findBestReference(root, 0, total, minLength, 0);
    cout << minLength << "\n";
    return 0;
}
//Augusto C Fagundes