#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

ll mod_pow(ll a, ll n, const ll mod) {
    ll result = 1;
    while (n > 0) {
        if (n & 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int test_case = 1; test_case <= t; ++test_case) {
        int a, b, n, k;
        cin >> a >> b >> n >> k;

        const int sz = min(n, k);

        vector<int> cnt(k);
        vector<int> cnt2(k);
        for (int i = 1; i <= sz; ++i) {
            cnt[mod_pow(i, a, k)] += (n - i) / k + 1;
            cnt2[mod_pow(i, b, k)] += (n - i) / k + 1;
        }

        ll answer = 1ll * cnt[0] * cnt2[0] % MOD;
        for (int i = 1; i < k; ++i) {
            answer = (answer + 1ll * cnt[i] * cnt2[k - i] % MOD) % MOD;
        }

        for (int i = 1; i <= sz; ++i) {
            if ((mod_pow(i, a, k) + mod_pow(i, b, k)) % k == 0) {
                answer -= (n - i) / k + 1;
            }
        }

        answer = (answer % MOD + MOD) % MOD;

        cout << "Case #" << test_case << ": " << answer << '\n';
    }

    return 0;
}