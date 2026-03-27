#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

ll dijkstra(const vector<vector<pair<ll, pair<int, int>>>>& adj) {
    vector<ll> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [dist, now] = pq.top();
        pq.pop();

        dist = -dist;

        if (distance[now] < dist) {
            continue;
        }

        for (auto& [t, e] : adj[now]) {
            auto [next, c] = e;
            ll cost = max(dist, t) + c;

            if (cost < distance[next]) {
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance.back();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x, y;
    cin >> n >> k >> x >> y;

    vector<vector<pair<ll, pair<int, int>>>> adj(n + 1);
    for (int i = 0; i < x; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(0, make_pair(v, c));
        adj[v].emplace_back(0, make_pair(u, c));
    }

    for (int i = 0; i < y; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(k, make_pair(v, c));
        adj[v].emplace_back(k, make_pair(u, c));
    }

    cout << dijkstra(adj);

    return 0;
}