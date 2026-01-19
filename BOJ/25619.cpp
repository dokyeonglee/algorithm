#include <iostream>
#include <queue>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

vector<bool> bfs(const vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(adj.size());
    visited[1] = true;

    queue<int> q;
    q.emplace(1);

    while (!q.empty()) {
        const int now = q.front();
        q.pop();
        for (auto& [next, c] : adj[now]) {
            if (!visited[next]) {
                visited[next] = true;
                q.emplace(next);
            }
        }
    }

    return visited;
}

vector<ll> dijkstra(const vector<vector<pair<int, int>>>& adj) {
    vector<ll> distance(adj.size(), INF);
    distance[1] = 0;

    priority_queue<pair<ll, int>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        const ll dist = -pq.top().first;
        const int now = pq.top().second;
        pq.pop();

        if (dist > distance[now]) {
            continue;
        }

        for (auto& [next, c] : adj[now]) {
            if (c < 0) {
                continue;
            }
            const ll cost = dist + c;
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

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    vector<bool> has_negative_edge(n + 1);

    for (int i = 0; i < m; ++i) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;

        adj[u].emplace_back(v, a + b);
        adj[v].emplace_back(u, a + b);
        if (a + b < 0) {
            has_negative_edge[u] = true;
            has_negative_edge[v] = true;
        }
    }

    ll t;
    cin >> t;

    t *= 2;

    vector<int> answer;

    auto reachable = bfs(adj);
    for (int i = 1; i <= n; ++i) {
        if (reachable[i] && has_negative_edge[i]) {
            for (int u = 2; u <= n; ++u) {
                if (reachable[u]) {
                    answer.push_back(u);
                }
            }
            break;
        }
    }

    if (answer.size() == 0) {
        auto distance = dijkstra(adj);
        for (int i = 2; i <= n; ++i) {
            if (distance[i] <= t) {
                answer.push_back(i);
            }
        }
    }

    cout << answer.size() << '\n';
    for (const int u : answer) {
        cout << u << ' ';
    }

    return 0;
}