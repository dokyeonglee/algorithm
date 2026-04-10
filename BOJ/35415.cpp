#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

vector<ll> dijkstra(const vector<vector<pair<int, int>>>& adj, const int src) {
    vector<ll> distance(adj.size(), INF);
    distance[src] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [dist, now] = pq.top();
        pq.pop();

        dist = -dist;

        if (dist > distance[now]) {
            continue;
        }

        for (auto [next, c] : adj[now]) {
            ll cost = dist + c;
            if (cost < distance[next]) {
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    ll answer = INF;

    auto distance_k = dijkstra(adj, k);
    if (distance_k[1] == INF || distance_k[n] == INF) {
        answer = -1;
    } else {
        answer = distance_k[1] + distance_k[n];

        auto distance_1 = dijkstra(adj, 1);
        auto distance_n = dijkstra(adj, n);

        for (int i = 1; i <= n; ++i) {
            if (distance_k[i] <= t) {
                answer = min(answer, distance_1[i] + distance_n[i] + t);
            }
        }
    }

    cout << answer;

    return 0;
}