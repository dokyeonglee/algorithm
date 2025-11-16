#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[1] = 0;

    for (int i = 1; i < n; ++i) {
        if (2 * i <= n) {
            dp[2 * i] = min(dp[2 * i], dp[i] + 1);
        }
        if (3 * i <= n) {
            dp[3 * i] = min(dp[3 * i], dp[i] + 1);
        }
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    }

    int idx = n;

    cout << dp[n] << '\n';
    while (idx >= 1) {
        cout << idx << ' ';
        if (idx % 2 == 0 && dp[idx / 2] == dp[idx] - 1) {
            idx /= 2;
        } else if (idx % 3 == 0 && dp[idx / 3] == dp[idx] - 1) {
            idx /= 3;
        } else {
            --idx;
        }
    }

    return 0;
}