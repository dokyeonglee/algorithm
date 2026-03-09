#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

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

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        ll answer = 0;
        for (int i = k + 1; i >= 2; --i) {
            answer = (answer + mod_pow(i, n, MOD)) % MOD;
        }
        cout << answer << '\n';
    }

    return 0;
}