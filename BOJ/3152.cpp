#include <iostream>

using namespace std;
using ll = long long;

int solve(ll p, ll n) {
    int cnt1 = 0;
    int cnt2 = 0;

    while (n > 0) {
        int mod = n % p;
        if (mod == 1) {
            ++cnt1;
        } else if (mod == 2) {
            ++cnt2;
        } else if (mod > 2) {
            return 0;
        }
        n /= p;
    }

    return (cnt1 == 1 && cnt2 > 0) || (cnt1 == 2 && cnt2 == 0);
}

int main() {
    ll p, n1, n2, n3, n4;
    cin >> p >> n1 >> n2 >> n3 >> n4;

    cout << solve(p, n1) << ' ' << solve(p, n2) << ' ' << solve(p, n3) << ' ' << solve(p, n4);

    return 0;
}