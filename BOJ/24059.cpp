#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % mod;
        }
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll mod_pow_tower(const vector<int>& arr, const int n, const int mod) {
    if (n == 0) {
        return arr[0] % mod;
    } else if (n == 1) {
        return mod_pow(arr[1], arr[0], mod);
    } else if (n == 2) {
        if (arr[2] % mod == 0) {
            return 0;
        }
        ll exp = mod_pow(arr[1], arr[0], mod - 1);
        return mod_pow(arr[2], exp, mod);
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    for (auto& a : arr) {
        cin >> a;
    }

    int mod;
    cin >> mod;

    cout << mod_pow_tower(arr, n, mod);

    return 0;
}