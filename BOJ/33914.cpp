#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAX_N = 2000;

long long mod_pow(long long a, long long n, const int mod = MOD) {
    long long result = 1;
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

long long nCr(const vector<int>& fac, const vector<int>& fac_inv, const int n, const int r, const int mod = MOD) {
    if (r < 0 || r > n) {
        return 0;
    }
    return 1ll * fac[n] * fac_inv[r] % mod * fac_inv[n - r] % mod;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> fac(MAX_N + 1);
    vector<int> fac_inv(MAX_N + 1);

    init_factorial_and_mod_inv(fac, fac_inv);

    int x, y;
    cin >> x >> y;

    long long answer = 0;

    if (x % 2 == 0 and x <= 2 * y) {
        const int n = (x + y) / 3;
        const int r = x / 2;
        answer = nCr(fac, fac_inv, n, r) * mod_pow(3, r) % MOD;
    }
    
    cout << answer << '\n';

    return 0;
}