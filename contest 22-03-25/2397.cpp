#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int sides[3] = {A, B, C};
    sort(sides, sides + 3);
    
    if (sides[0] + sides[1] <= sides[2]) {
        cout << 'n' << "\n";
    } else {
        int a2 = sides[0] * sides[0];
        int b2 = sides[1] * sides[1];
        int c2 = sides[2] * sides[2];
        
        if (a2 + b2 > c2) cout << 'a' << "\n";
        else if (a2 + b2 == c2) cout << 'r' << "\n";
        else cout << 'o' << "\n";
    }
    
    return 0;
}
//Augusto C Fagundes