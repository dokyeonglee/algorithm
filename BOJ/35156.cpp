#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

ll mod_pow(ll a, ll n, const ll mod) {
    a %= mod;
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
        ll n, l, r;
        cin >> n >> l >> r;

        ll answer = mod_pow(r - l + 1, n, MOD);
        answer -= 2 * mod_pow(r - l, n, MOD);
        if (l != r) {
            answer += mod_pow(r - l - 1, n, MOD);
        }
        answer = (answer % MOD + MOD) % MOD;
        cout << answer << '\n';
    }

    return 0;
}