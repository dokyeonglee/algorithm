#include <iostream>
#include <vector>
#include <climits>

using namespace std;

constexpr int MOD = 1e9 + 7;

long long mod_pow(long long a, long long n) {
    long long result = 1;
    while (n > 0) {
        if (n & 1) {
            result = result * a % MOD;
        }
        a = a * a % MOD;
        n >>= 1;
    }
    return result;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int p, c, k;
    cin >> p >> c >> k;

    vector<long long> balance(p);
    for (auto& b : balance) {
        cin >> b;
    }

    vector<long long> d(p + 1);
    for (int i = 1; i < p; i++) {
        d[i] = (balance[i] - balance[i - 1]) % MOD;
    }

    for (int i = 1; i < p; i++) {
        d[p] = (c * d[p] - d[i]) % MOD;
    }

    d[p] *= c;
    d[p] %= MOD;

    int c_p = mod_pow(c, p);
    int c_p_inv = mod_pow(c_p, MOD - 2) % MOD;

    d[0] = d[p] * c_p_inv % MOD;

    long long d_k = abs(d[k % p]) * mod_pow(c, k - k % p) % MOD;
    cout << d_k;

    return 0;
}