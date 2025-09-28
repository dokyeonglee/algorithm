#include <iostream>
#include <vector>

using namespace std;

int calculate_lcs_length(const string& a, const string& b) {
    const int n = a.size();
    const int m = b.size();

    vector<vector<int>> dp(2, vector<int>(m + 1));
    int toggle = 0;

    for (int i = 1; i <= n; ++i) {
        toggle ^= 1;
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[toggle][j] = dp[toggle ^ 1][j - 1] + 1;
            } else {
                dp[toggle][j] = max(dp[toggle][j - 1], dp[toggle ^ 1][j]);
            }
        }
    }

    return dp[toggle][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a;
    cin >> a;

    string b;
    cin >> b;

    const int lcs_length = calculate_lcs_length(a, b);
    cout << a.size() + b.size() - lcs_length << '\n';

    return 0;
}