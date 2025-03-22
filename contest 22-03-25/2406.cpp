#include <iostream>
#include <stack>
using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string A;
        cin >> A;
        cout << (isValid(A) ? 'S' : 'N') << "\n";
    }
    return 0;
}
//Augusto C Faguundes