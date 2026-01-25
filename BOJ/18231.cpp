#include <iostream>
#include <vector>

using namespace std;

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

    vector<bool> destroyed(n + 1);

    int k; 
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int u;
        cin >> u;
        destroyed[u] = true;
    }

    vector<int> cand;

    for (int i = 1; i <= n; ++i) {
        if (destroyed[i]) {
            int cnt = 0;
            for (const int j : adj[i]) {
                cnt += destroyed[j];
            }
            if (cnt == adj[i].size()) {
                cand.push_back(i);
            }
        }
    }

    vector<bool> foo(n + 1);
    for (const int i : cand) {
        foo[i] = true;
        for (const int j : adj[i]) {
            foo[j] = true;
        }
    }

    if (destroyed == foo) {
        cout << cand.size() << '\n';
        for (const int i : cand) {
            cout << i << ' ';
        }
    } else {
        cout << -1 << '\n';
    }

    return 0;
}