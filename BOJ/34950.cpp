#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll n, l;
    cin >> n >> l;

    ll left = 0;
    ll right = l;

    while (n > 0) {
        if (right - left + 1 == n) {
            for (int i = 0; i < n; ++i) {
                cout << left + i << ' ';
            }
            n = 0;
            break;
        }

        int sz = n / 2;
        for (int i = 0; i < sz; ++i) {
            cout << left + i << ' ';
        }

        ll mid = (left + right) / 2;
        left = mid + 1;
        n -= sz;
    }

    return 0;
}