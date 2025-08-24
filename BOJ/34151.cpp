#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr ll MOD = 998244353;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}

ll geometric_series(const ll a, const ll r, const ll n) {
    if (r == 1) {
        return a * n % MOD;
    }

    ll result = (mod_pow(r, n) - 1 + MOD) % MOD * mod_pow(r - 1, MOD - 2) % MOD;
    result = result * a % MOD;
    return result;
}

ll calculate_gcd_sum(const ll p, ll n, ll m) {
    if (n > m) {
        swap(n, m);
    }

    const ll p_power_n = mod_pow(p, n);
    const ll p_power_m = mod_pow(p, m);
    return (geometric_series(p_power_n, p_power_n, (m - 1) / n) + p_power_m) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll p, n, m;
        cin >> p >> n >> m;
        cout << calculate_gcd_sum(p, n, m) << '\n';
    }

    return 0;
}