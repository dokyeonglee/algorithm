#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c, m;
    cin >> c >> m;

    vector<vector<int>> arr(m, vector<int>(c + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(2, vector<int>(c + 1));
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= c; ++j) {
            dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j]);
            for (int k = c; k >= j; --k) {
                dp[i & 1][k] = max(dp[i & 1][k], dp[i & 1 ^ 1][k - j] + arr[i][j]);
            }
        }
    }

    cout << dp[m & 1 ^ 1][c];

    return 0;
}