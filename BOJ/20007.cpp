#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& adj, const int src) {
    vector<int> distance(adj.size(), INF);
    distance[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        auto [dist, now] = pq.top();
        pq.pop();

        dist = -dist;

        if (dist > distance[now]) {
            continue;
        }

        for (auto [next, c] : adj[now]) {
            int cost = dist + c;
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

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    x /= 2;

    auto distance = dijkstra(adj, y);
    sort(distance.begin(), distance.end());

    int answer = 1;
    if (distance.back() > x) {
        answer = -1;
    } else {
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            if (sum + distance[i] <= x) {
                sum += distance[i];
            } else {
                ++answer;
                sum = distance[i];
            }
        }
    }

    cout << answer;

    return 0;
}