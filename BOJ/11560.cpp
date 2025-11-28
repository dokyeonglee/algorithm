#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<ll>> dp(21, vector<ll>(211));
    for (int i = 1; i <= 20; ++i) {
        dp[i][0] = 1;
    }

    dp[1][1] = 1;

    for (int i = 2; i <= 20; ++i) {
        for (int j = 1; j <= i * (i + 1) / 2; ++j) {
            for (int k = 0; k <= min(i, j); ++k) {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int k, n;
        cin >> k >> n;

        cout << dp[k][n] << '\n';
    }

    return 0;
}