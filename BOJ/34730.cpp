#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

ll dijkstra(const vector<vector<pair<int, pair<int, int>>>>& adj, const int s, const int t, const int k) {
    vector<vector<ll>> distance(adj.size(), vector<ll>(k, INF));
    distance[s][0] = 0;

    priority_queue<pair<ll, pair<int, int>>> pq;
    pq.push({0, {s, 0}});

    while (!pq.empty()) {
        const auto [dist, now] = pq.top();
        pq.pop();

        if (distance[now.first][now.second] < -dist) {
            continue;
        }

        for (const auto [next, e] : adj[now.first]) {
            if (now.second % e.second == 0) {
                const ll cost = -dist + e.first;
                if (distance[next][(now.second + e.first) % k] > cost) {
                    distance[next][(now.second + e.first) % k] = cost;
                    pq.push({-cost, {next, (now.second + e.first) % k}});
                }
            }
        }
    }

    return *min_element(distance[t].begin(), distance[t].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, s, t;
    cin >> n >> m >> k >> s >> t;

    vector<vector<pair<int, pair<int, int>>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c, p;
        cin >> u >> v >> c >> p;
        adj[u].push_back({v, {c, p}});
    }

    ll answer = dijkstra(adj, s, t, k);
    if (answer == INF) {
        answer = -1;
    }

    cout << answer;

    return 0;
}