#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int mod = 998244353;

constexpr int MAX_N = 5000;

ll mod_pow(ll a, ll n, ll mod) {
    ll result = 1;
    while (n > 0) {
        if (n & 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dp(MAX_N + 1);
    vector<int> dp2(MAX_N / 3 + 1);
    dp[0] = 1;
    dp2[1] = 1;

    for (int i = 1; i < dp2.size() - 1; ++i) {
        dp2[i + 1] = 2ll * (2 * i + 1) * dp2[i] % mod * mod_pow(i + 2, mod - 2, mod) % mod;
    }

    for (int i = 2; i < dp.size(); ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        if (i % 3 == 1) {
            dp[i] = (dp[i] - dp2[i / 3] + mod) % mod;
        }
    }

    dp[1] = -1;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}