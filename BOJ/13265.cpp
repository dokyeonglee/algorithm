#include <iostream>
#include <vector>

using namespace std;

bool dfs(const vector<vector<int>>& adj, vector<int>& colors, const int now, const int c) {
    colors[now] = c;
    for (const int next : adj[now]) {
        if (colors[next] == c) {
            return false;
        }
        if (colors[next] == -1) {
            if (!dfs(adj, colors, next, c ^ 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool check = true;
        vector<int> colors(n + 1, -1);
        for (int i = 1; i <= n; ++i) {
            if (colors[i] == -1) {
                if (!dfs(adj, colors, i, 0)) {
                    check = false;
                    break;
                }
            }
        }

        if (check) {
            cout << "possible\n";
        } else {
            cout << "impossible\n";
        }
    }

    return 0;
}