#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, c;
    cin >> n >> k >> c;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> prefix_sum(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    const int carry_limit = n - k;
    int carried = 0;

    for (int x = 1; x <= c; ++x) {
        while (carried < carry_limit && prefix_sum[carried + 1] <= x) {
            ++carried;
        }

        cout << prefix_sum[carried + k] - prefix_sum[carried] << '\n';
    }

    return 0;
}