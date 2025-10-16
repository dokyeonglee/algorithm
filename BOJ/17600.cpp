#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    vector<int> dp(coins.back() * 2 + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j < dp.size(); ++j) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }

    int idx = 0;

    for (int i = coins[0]; i < dp.size(); ++i) {
        while (idx + 1 < n && coins[idx + 1] <= i) {
            ++idx;
        }
        if (dp[i - coins[idx]] + 1 != dp[i]) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}