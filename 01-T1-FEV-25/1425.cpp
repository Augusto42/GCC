#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

// NOT WORKING YET!!!

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0)
            break;

        if (N < 9) {
            cout << (M == 1 ? "Let me try!" : "Don't make fun of me!") << "\n";
            continue;
        }

        if (M == 1 || M == 4 || M == 9) {
            cout << "Let me try!" << "\n";
            continue;
        }

        unordered_set<int> dp;
        dp.insert(0);
        bool ok = false;
        int jmax = static_cast<int>(sqrt(N + 224)) + 1;

        for (int j = 4; j <= jmax; j++) {
            int L = 2 * j - 1;
            unordered_set<int> ndp;
            for (auto d : dp) {
                int a = d + L;
                if (a <= N - 9)
                    ndp.insert(a);
                int b = d - L;
                if (b >= -8)
                    ndp.insert(b);
            }
            dp = move(ndp);
            if (dp.find(M - 9) != dp.end()) {
                ok = true;
                break;
            }
            if (dp.empty())
                break;
        }
        cout << (ok ? "Let me try!" : "Don't make fun of me!") << "\n";
    }
    return 0;
}
