#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < k; ++i) {
        int u, v, score;
        cin >> u >> v >> score;
        
        if (u < v) {
            adj[v].emplace_back(u, score);
        }
    }

    vector<int> dp(n + 1, -INF);
    dp[1] = 0;

    for (int i = 2; i <= m; ++i) {
        int temp = dp[n];
        for (int u = n; u > 1; --u) {
            for (const auto [v, score] : adj[u]) {
                dp[u] = max(dp[u], dp[v] + score);
            }
        }
        if (dp[n] == temp) {
            break;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}