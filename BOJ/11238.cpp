#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

vector<vector<ll>> mat_mul(vector<vector<ll>>& a, vector<vector<ll>>& b, int mod) {
    vector<vector<ll>> result(a.size(), vector<ll>(b[0].size()));
    for (int k = 0; k < a[0].size(); ++k) {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < b[0].size(); ++j) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= mod;
            }
        }
    }
    return result;
}

vector<vector<ll>> pow(vector<vector<ll>> arr, int n, int mod) {
    vector<vector<ll>> result(arr.size(), vector<ll>(arr[0].size()));
    for (int i = 0; i < result.size(); ++i) {
        result[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            result = mat_mul(result, arr, mod);
        }
        arr = mat_mul(arr, arr, mod);
        n >>= 1;
    }
    return result;
}

int fib(int n) {
    return pow({{1, 1}, {1, 0}}, n, mod)[0][1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << fib(gcd(n, m)) << '\n';
    }

    return 0;
}