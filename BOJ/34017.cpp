#include <iostream>

using namespace std;
using ll = long long;

ll sequence_sum(ll n, const int* base) {
    static int offset[] = {1, 2, 0};
    if (n < 3) {
        return base[n];
    }
    return 2 * sequence_sum(n / 3 + offset[n % 3], base) + 2 * (n / 3) + 3 - offset[n % 3];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    int base[] = {0, 1, 3};

    while (q--) {
        ll n;
        cin >> n;
        cout << sequence_sum(n, base) << '\n';
    }

    return 0;
}