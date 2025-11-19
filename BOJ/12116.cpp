#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    
    for (ll i = 1; i * i <= 2 * n; ++i) {
        if (2 * n % i == 0 && (i + 2 * n / i) % 2 == 1) {
            ll y = (i + 2 * n / i - 1) / 2;
            ll x = 2 * n / i - y;
            if (x != y) {
                cout << x << ' ' << y << '\n';
            }
        }
    }

    return 0;
}