#include <iostream>
#include <deque>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        deque<char> beijuText;
        auto it = beijuText.begin();
        for (char c : line) {
            if (c == '[') {
                it = beijuText.begin();
            } else if (c == ']') {
                it = beijuText.end();
            } else {
                it = beijuText.insert(it, c);
                ++it;
            }
        }
        for (char c : beijuText) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}
 // Augusto C Fagundes