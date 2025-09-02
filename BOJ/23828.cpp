#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_VALUE = 100000;
constexpr int MOD = 1e9 + 7;

ll good_sequence_product_sum(const vector<int>& cnt, const int m) {
    vector<ll> weighted_values;

    for (int i = 1; i <= MAX_VALUE; ++i) {
        if (cnt[i] > 0) {
            weighted_values.push_back(1ll * i * cnt[i] % MOD);
        }
    }

    vector<ll> dp(m + 1);
    dp[0] = 1;

    for (const ll value : weighted_values) {
        for (int j = m; j >= 1; --j) {
            dp[j] = (dp[j] + dp[j - 1] * value) % MOD;
        }
    }

    return dp[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> cnt(MAX_VALUE + 1);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        ++cnt[x];
    }

    cout << good_sequence_product_sum(cnt, m) << '\n';

    return 0;
}