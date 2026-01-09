#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(const vector<vector<int>>& tree, vector<int>& depth, const int now, const int p) {
    for (const int next : tree[now]) {
        if (next != p) {
            depth[next] = depth[now] + 1;
            dfs(tree, depth, next, now);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> depth(n);

        dfs(tree, depth, 0, -1);

        int u = max_element(depth.begin(), depth.end()) - depth.begin();
        depth[u] = 0;

        dfs(tree, depth, u, -1);

        cout << (*max_element(depth.begin(), depth.end()) + 1) / 2 << '\n';
    }

    return 0;
}