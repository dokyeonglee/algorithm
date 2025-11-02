#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int k;
    cin >> k;

    vector<pair<int, int>> coins(k);
    for (auto& [p, n] : coins) {
        cin >> p >> n;
    }

    vector<int> dp(t + 1);
    dp[0] = 1;

    for (const auto [p, n] : coins) {
        for (int i = t; i >= p; --i) {
            for (int j = 1; j <= n && j * p <= i; ++j) {
                dp[i] += dp[i - j * p];
            }
        }
    }

    cout << dp[t] << '\n';

    return 0;
}