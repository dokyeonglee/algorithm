#include <iostream>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

vector<int> calculate_distance(const vector<vector<int>>& tree, const vector<int>& src) {
    vector<int> distance(tree.size(), INF);
    queue<int> q;

    for (const int x : src) {
        distance[x] = 0;
        q.push(x);
    }

    while (!q.empty()) {
        const int now = q.front();
        q.pop();

        for (const int next : tree[now]) {
            if (distance[next] == INF) {
                distance[next] = distance[now] + 1;
                q.push(next);
            }
        }
    }

    return distance;
}

bool can_escape(const vector<vector<int>>& tree, const int thief, const int police1, const int police2) {
    if (tree[thief].size() == 1) {
        return true;
    }

    const vector<int> distance_from_thief = calculate_distance(tree, {thief});
    const vector<int> distance_from_police = calculate_distance(tree, {police1, police2});

    for (int i = 1; i < tree.size(); ++i) {
        if (tree[i].size() == 1) {
            if (distance_from_thief[i] < distance_from_police[i]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int thief, police1, police2;
    cin >> thief >> police1 >> police2;

    if (can_escape(tree, thief, police1, police2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


    return 0;
}