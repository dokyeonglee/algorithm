#include <iostream>

using namespace std;
using ll = long long;

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
    int p, k, t;
    cin >> p >> k >> t;

    ll answer = mod_pow(k, t, p);
    if (t % 2) {
        answer = p - answer;
    }

    cout << answer;

    return 0;
}