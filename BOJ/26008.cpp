#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

ll mod_pow(ll a, ll n, const ll MOD) {
    ll result = 1;
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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a;
    cin >> n >> m >> a;

    int h;
    cin >> h;

    cout << mod_pow(m, n - 1, MOD) << '\n';

    return 0;
}