#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int P, A, R;
    while (cin >> P >> A >> R, P || A || R) {
        unordered_set<string> pearls;
        string line;
        cin.ignore();

        for (int i = 0; i < P; ++i) {
            getline(cin, line);
            pearls.insert(line);
        }

        unordered_map<string, int> student_count;
        int max_count = 0;
        
        for (int i = 0; i < A; ++i) {
            string student_name;
            getline(cin, student_name);
            int count = 0;

            for (int j = 0; j < R; ++j) {
                getline(cin, line);
                if (pearls.count(line)) {
                    count++;
                }
            }

            student_count[student_name] = count;
            max_count = max(max_count, count);
        }

        vector<string> top_students;
        for (const auto& pair : student_count) {
            if (pair.second == max_count) {
                top_students.push_back(pair.first);
            }
        }
        
        sort(top_students.begin(), top_students.end());
        for (size_t i = 0; i < top_students.size(); ++i) {
            if (i > 0) cout << ", ";
            cout << top_students[i];
        }
        cout << "\n";
    }
    return 0;
}
// Augusto C Fagundes