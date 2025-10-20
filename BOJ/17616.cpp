#include <iostream>
#include <queue>

using namespace std;

constexpr int WIN = 1;
constexpr int LOSE = -1;

pair<int, int> bfs(const vector<vector<pair<int, int>>>& adj, const int x) {
    vector<bool> visited(adj.size());
    visited[x] = true;

    queue<pair<int, int>> q;
    q.emplace(x, WIN);
    q.emplace(x, LOSE);
    
    int max_rank = 0;
    int min_rank = adj.size();

    while (!q.empty()) {
        const auto [now, result] = q.front();
        q.pop();

        if (result == WIN) {
            --min_rank;
        } else {
            ++max_rank;
        }

        for (const auto [next, result2] : adj[now]) {
            if (!visited[next] && result == result2) {
                visited[next] = true;
                q.emplace(next, result);
            }
        }
    }

    return {max_rank, min_rank};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u].emplace_back(v, WIN);
        adj[v].emplace_back(u, LOSE);
    }

    const auto [max_rank, min_rank] = bfs(adj, x);
    cout << max_rank << ' ' << min_rank << '\n';

    return 0;
}