#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> left(n + 1);
    vector<int> right(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> left[i];
    }

    for (int i = 1; i <= n; ++i) {
        cin >> right[i];
    }

    vector<vector<int>> dp(n + 1,vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (abs(left[i] - right[j]) <= 4) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][n] << '\n';

    return 0;
}