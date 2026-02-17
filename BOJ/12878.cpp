#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 10007;

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

    int n;
    cin >> n;

    ll answer = mod_pow(2, n - 1, MOD);
    answer *= answer + 1;
    cout << answer % MOD;

    return 0;
}