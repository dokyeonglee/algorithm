#include <iostream>
#include <vector>

using namespace std;

constexpr int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, ri, rg;
    cin >> n >> ri >> rg;

    vector<pair<int, int>> arr(n);
    for (auto& a : arr) {
        cin >> a.first >> a.second;
    }

    vector<vector<int>> dp(ri + 1, vector<int>(rg + 1, INF));
    dp[0][0] = 0;

    for (auto& [x, y] : arr) {
        for (int i = ri; i >= 0; --i) {
            int idx = max(0, i - x);
            for (int j = rg; j >= 0; --j) {
                dp[i][j] = min(dp[i][j], dp[idx][max(0, j - y)] + 1);
            }
        }
    }

    if (dp[ri][rg] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[ri][rg] << '\n';
    }

    return 0;
}