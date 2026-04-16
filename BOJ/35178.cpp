#include <iostream>

using namespace std;
using ll = long long;

constexpr int MOD = 998244353;

ll mod_pow(ll a, ll n, const ll mod) {
    ll result = 1;
    while (n) {
        if (n & 1) {
            result = result * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return result;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    cout << mod_pow(m, n - q, MOD);

    return 0;
}