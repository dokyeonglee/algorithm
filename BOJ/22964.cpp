#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

ll mod_pow(ll a, ll n, ll mod) {
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

    ll n, k, x;
    cin >> n >> k >> x;

    const int sz = n - k + 1;
    ll answer = k * (mod_pow(x * (x + 1) / 2, 2, MOD) * mod_pow(x, n + k - 2, MOD) % MOD) % MOD;
    for (int i = 0; i < sz; ++i) {
        cout << answer << ' ';
    }

    return 0;
}