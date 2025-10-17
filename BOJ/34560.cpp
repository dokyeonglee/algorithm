#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Character{
    string name;
    int potenza;
    int agilita;
    int surrealismo;

    bool operator<(const Character& other) {
        return name < other.name;
    }

    int win_count(const Character& other) {
        return (other.potenza <= potenza) + (other.agilita <= agilita) + (other.surrealismo <= surrealismo);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Character> characters(n);
    for (auto& [name, potenza, agilita, surrelisom] : characters) {
        cin >> name >> potenza >> agilita >> surrelisom;
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n);

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            const int win_count1 = characters[i].win_count(characters[j]);
            const int win_count2 = characters[j].win_count(characters[i]);
            if (win_count1 > win_count2) {
                adj[i].push_back(j);
                ++in_degree[j];
            } else if (win_count1 < win_count2) {
                adj[j].push_back(i);
                ++in_degree[i];
            }
        }
    }

    vector<bool> never_lose(n);
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            never_lose[i] = true;
            q.push(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (q.empty()) {
            cout << "Paradoxe Absurdo\n";
            return 0;
        }

        int now = q.front();
        q.pop();

        for (const int next : adj[now]) {
            if (--in_degree[next] == 0) {
                q.push(next);
            }
        }
    }

    vector<string> answer;

    for (int i = 0; i < n; ++i) {
        if (never_lose[i]) {
            answer.push_back(characters[i].name);
        }
    }

    sort(answer.begin(), answer.end());
    for (const auto& name : answer) {
        cout << name << '\n';
    }

    return 0;
}