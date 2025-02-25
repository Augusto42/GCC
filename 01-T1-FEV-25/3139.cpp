#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;
    
    vector<int> D(30);
    long long sum = 0;
    for (int i = 0; i < 30; ++i) {
        cin >> D[i];
        sum += D[i];
    }
    
    int days = 0;
    while (N < M) {
        int new_followers = ceil(static_cast<double>(sum) / 30);
        N += new_followers;
        sum = sum - D[0] + new_followers;
        D.erase(D.begin());
        D.push_back(new_followers);
        days++;
    }
    
    cout << days << "\n";
    return 0;
}
//Augusto C Fagundes