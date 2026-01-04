#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MAX_N = 2000;
constexpr int MOD = 1e9 + 7;

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

    vector<ll> fac(MAX_N + 1);
    fac[0] = 1;
    for (int i = 1; i <= MAX_N; ++i) {
        fac[i] = i * fac[i - 1] % MOD;
    }

    vector<ll> fac_inv(MAX_N + 1);
    fac_inv[MAX_N] = mod_pow(fac[MAX_N], MOD - 2, MOD);
    for (int i = MAX_N; i > 0; --i) {
        fac_inv[i - 1] = i * fac_inv[i] % MOD;
    }
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        bool check = true;
        ll answer = fac[n];
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if (x == 0) {
                check = false;
            }
            answer = answer * fac_inv[x] % MOD;
        }

        if (check) {
            answer = 1;
        }
        cout << answer << '\n';
    }

    return 0;
}