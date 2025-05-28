#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
constexpr int MOD = 1e9 + 7;

ll mod_pow(ll a, ll n, const int mod = MOD) {
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

void init_factorial_and_mod_inv(vector<int>& fac, vector<int>& fac_inv, const int mod = MOD) {
    fac[0] = 1;
    for (int i = 1; i < fac.size(); ++i) {
        fac[i] = 1ll * i * fac[i - 1] % mod;
    }

    fac_inv.back() = mod_pow(fac.back(), mod - 2, mod);
    for (int i = fac_inv.size() - 1; i > 0; --i) {
        fac_inv[i - 1] = 1ll * i * fac_inv[i] % mod;
    }
}

ll nCr(const vector<int>& fac, const vector<int>& fac_inv, const int n, const int r, const int mod = MOD) {
    if (r < 0 || r > n) {
        return 0;
    }
    return 1ll * fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod;
}

ll nHr(const vector<int>& fac, const vector<int>& fac_inv, const int n, const int r, const int mod = MOD) {
    return nCr(fac, fac_inv, n + r - 1, r, mod);
}

ll count_best_arrangements(const vector<int>& fac, const vector<int>& fac_inv, const int n, const int m, const int mod = MOD) {
    if (m <= (n + 1) / 2) {
        return nHr(fac, fac_inv, m + 1, n - 2 * m + 1, mod);
    }
    return nCr(fac, fac_inv, m - 1, n - m, mod);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> fac(n + 1);
    vector<int> fac_inv(n + 1);

    init_factorial_and_mod_inv(fac, fac_inv);

    cout << count_best_arrangements(fac, fac_inv, n, m);

    return 0;
}