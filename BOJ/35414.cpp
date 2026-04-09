#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result, int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, result, v);
            result.push_back(v);
        }
    }
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
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1);
    vector<int> answer;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(adj, visited, answer, i);
        }
    }

    cout << answer.size() << '\n';
    for (int u : answer) {
        cout << u << '\n';
    }

    return 0;
}