#include <iostream>

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
    return result;
}

int main() {

    int p, q, n;
    cin >> p >> q >> n;

    ll x = 0;
    ll y = 0;
    ll a = p * mod_pow(q, MOD - 2, MOD) % MOD;
    ll power_of_a = 1;

    for (int i = 0; i < n; ++i) {
        if ((x + 2) * q < p * x) {
            power_of_a = a * power_of_a % MOD;
        } else if (i & 1) {
            ++x;
        } else {
            ++y;
        }
        cout << x * (x + 1) / 2 * y * (y + 1) / 2 % MOD * power_of_a % MOD << ' ';
    }

    return 0;
}