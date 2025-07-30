#include <iostream>
#include <queue>

using namespace std;

constexpr int SCHOOL = 1;

vector<int> calculate_distance(const vector<vector<int>>& adj, const int start) {
    vector<int> distance(adj.size(), -1);
    distance[start] = 0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (const int next : adj[now]) {
            if (distance[next] == -1) {
                distance[next] = distance[now] + 1;
                q.push(next);
            }
        }
    }

    return distance;
}

int find_must_pass_node(const vector<vector<int>>& adj) {
    const int n = adj.size() - 1;
    const int home = n;

    const auto distance_from_school = calculate_distance(adj, SCHOOL);
    const auto distance_from_home = calculate_distance(adj, home);
    const int school_to_home = distance_from_school[home];

    vector<vector<int>> nodes_at_distance(school_to_home);

    for (int i = 1; i <= n; ++i) {
        if (i == SCHOOL || i == home) {
            continue;
        }

        bool is_on_shortest_path = 
            (distance_from_school[i] + distance_from_home[i] == school_to_home);

        if (is_on_shortest_path) {
            nodes_at_distance[distance_from_school[i]].push_back(i);
        }
    }

    for (int d = 1; d < school_to_home; ++d) {
        if (nodes_at_distance[d].size() == 1) {
            return nodes_at_distance[d][0];
        }
    }

    return SCHOOL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << find_must_pass_node(adj) << '\n';

    return 0;
}