#include <iostream>
#include <vector>
using namespace std;

int min_pa_partitions(const vector<int>& seq) {
    int n = seq.size();
    if (n == 1) return 1;
    
    int count = 1;
    for (int i = 2; i < n; ++i) {
        if (seq[i] - seq[i - 1] != seq[i - 1] - seq[i - 2]) {
            count++;
            i++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) cin >> seq[i];
    cout << min_pa_partitions(seq) << "\n";
    return 0;
}

//Augusto C Fagundes