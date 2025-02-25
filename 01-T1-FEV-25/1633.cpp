#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

struct Process {
    int t, c;
    Process(int t, int c) : t(t), c(c) {}
    bool operator>(const Process &other) const {
        return t > other.t;
    }
};

int main() {
    int N;
    while (cin >> N) {
        vector<Process> processes;
        for (int i = 0; i < N; ++i) {
            int t, c;
            cin >> t >> c;
            processes.emplace_back(t, c);
        }
        
        sort(processes.begin(), processes.end(), [](const Process &a, const Process &b) {
            return a.t < b.t;
        });
        
        ll current_time = 1, total_waiting_time = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int index = 0;
        
        while (index < N || !pq.empty()) {
            while (index < N && processes[index].t <= current_time) {
                pq.push(processes[index].c);
                ++index;
            }
            
            if (!pq.empty()) {
                int exec_time = pq.top();
                pq.pop();
                total_waiting_time += current_time - processes[index - pq.size() - 1].t;
                current_time += exec_time;
            } else {
                current_time = processes[index].t;
            }
        }
        
        cout << total_waiting_time << '\n';
    }
    return 0;
}

// Augusto C Fagundes