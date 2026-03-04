#include <iostream>
#include <queue>

using namespace std;

auto topology_sort(const vector<vector<int>>& adj, vector<int>& in_degree) {
    priority_queue<int> pq;
    for (int i = 1; i < in_degree.size(); ++i) {
        if (in_degree[i] == 0) {
            pq.emplace(-i);
        }
    }

    vector<int> result;
    for (int i = 1; i < adj.size(); ++i) {
        if (pq.empty()) {
            result.clear();
            break;
        }
        const int now = -pq.top();
        pq.pop();
        result.push_back(now);
        for (const int next : adj[now]) {
            if (--in_degree[next] == 0) {
                pq.emplace(-next);
            }
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++in_degree[v];
    }

    auto answer = topology_sort(adj, in_degree);
    if (answer.empty()) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (const int u : answer) {
            cout << u << ' ';
        }
    }

    return 0;
}