#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;
const string UOSPC = "UOSPC";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> costs(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> costs[i];
    }

    vector<vector<ll>> dp(2, vector<ll>(6, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i & 1][0] = dp[1 - (i & 1)][0];
        
        for (int j = 1; j <= 5; ++j) {
            if (str[i - 1] == UOSPC[j - 1]) {
                dp[i & 1][j] = min(dp[1 - (i & 1)][j], dp[1 - (i & 1)][j - 1] + costs[i]);
            } else {
                dp[i & 1][j] = dp[1 - (i & 1)][j];
            }
        }
    }

    if (dp[n & 1][5] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[n & 1][5] << '\n';
    }

    return 0;
}