#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    ll answer = 0;
    for (int i = 1; i <= n; ++i) {
        if (tree[i].size() > 2) {
            ll x = 1ll * (tree[i].size() - 1) * (tree[i].size() - 2) / 2;
            for (int j : tree[i]) {
                if (tree[j].size() > 2) {
                    ll y = 1ll * (tree[j].size() - 1) * (tree[j].size() - 2) / 2;
                    answer += x * y;
                }
            }
        }
    }

    answer /= 2;

    cout << answer << '\n';

    return 0;
}