#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

vector<int> bfs(const vector<vector<int>>& adj, const int src) {
    vector<int> distance(adj.size(), INF);
    distance[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty()) {
        const int now = q.front();
        q.pop();
        for (const int next : adj[now]) {
            if (distance[next] == INF) {
                distance[next] = distance[now] + 1;
                q.push(next);
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

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<vector<int>> distance(n + 1);
    for (int i = 1; i <= n; ++i) {
        distance[i] = bfs(adj, i);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int src, dst, k;
        cin >> src >> dst >> k;

        vector<int> arr(k);
        for (int& x : arr) {
            cin >> x;
        }

        sort(arr.begin(), arr.end(), [&](const int a, const int b) {
            return distance[src][a] < distance[src][b];
        });

        int now = src;
        long long dist = 0;
        for (const int x : arr) {
            dist += distance[now][x];
            now = x;
        }
        dist += distance[now][dst];

        if (dist < INF && dist == distance[src][dst]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }    

    return 0;
}