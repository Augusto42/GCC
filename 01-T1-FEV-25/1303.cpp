#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Team {
    int id, points, scored, conceded;
    
    Team(int i) : id(i), points(0), scored(0), conceded(0) {}
    
    double average() const {
        return conceded == 0 ? scored : static_cast<double>(scored) / conceded;
    }
};

bool compare(const Team &a, const Team &b) {
    if (a.points != b.points) return a.points > b.points;
    if (a.average() != b.average()) return a.average() > b.average();
    if (a.scored != b.scored) return a.scored > b.scored;
    return a.id < b.id;
}

int main() {
    int n, instance = 1;
    while (cin >> n && n != 0) {
        vector<Team> teams;
        for (int i = 1; i <= n; i++) teams.emplace_back(i);
        
        int x, y, z, w;
        for (int i = 0; i < (n * (n - 1)) / 2; i++) {
            cin >> x >> y >> z >> w;
            teams[x - 1].scored += y;
            teams[x - 1].conceded += w;
            teams[z - 1].scored += w;
            teams[z - 1].conceded += y;
            
            if (y > w) {
                teams[x - 1].points += 2;
                teams[z - 1].points += 1;
            } else {
                teams[z - 1].points += 2;
                teams[x - 1].points += 1;
            }
        }
        
        sort(teams.begin(), teams.end(), compare);
        
        if (instance > 1) cout << endl;
        cout << "Instancia " << instance++ << endl;
        for (size_t i = 0; i < teams.size(); i++) {
            if (i > 0) cout << " ";
            cout << teams[i].id;
        }
        cout << endl;
    }
    return 0;
}

// Augusto C Fagundes
