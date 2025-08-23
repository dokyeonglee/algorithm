#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using Query = pair<int, int>;

constexpr int MOD = 998244353;

ll mod_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = result * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return result;
}

int count_total_ones(const vector<int>& arr, const vector<Query>& queries) {
    const int n = arr.size() - 1;
    vector<int> flip_count(n + 2);

    for (const auto [l, r] : queries) {
        ++flip_count[l];
        --flip_count[r + 1];
    }

    for (int i = 1; i <= n; ++i) {
        flip_count[i] += flip_count[i - 1];
    }

    const int flipped = mod_pow(2, queries.size() - 1);
    const int never_flipped = 2 * flipped % MOD;
    int total_ones = 0;

    for (int i = 1; i <= n; ++i) {
        if (flip_count[i] == 0) {
            total_ones += arr[i] * never_flipped;
        } else {
            total_ones += flipped;
        }
        if (total_ones >= MOD) {
            total_ones %= MOD;
        }
    }

    return total_ones;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<Query> queries(k);
    for (auto& [l, r] : queries) {
        cin >> l >> r;
    }

    cout << count_total_ones(arr, queries) << '\n';

    return 0;
}