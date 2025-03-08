#include <iostream>
using namespace std;
//WRONG ANSWER 80%
const long long MOD = 1000000007;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long N;
    cin >> N;
    cout << power(2, N - 1, MOD) * 6 % MOD << "\n";
    return 0;
}
//Augusto C Fagundes