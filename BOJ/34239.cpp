#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll INF = 1e18;

ll max_plus_minus_sum(const vector<int>& arr) {
    ll result = -INF;

    for (int start = 0; start < 2; ++start) {
        int sign = 1;
        ll temp = 0;

        for (int i = start; i < arr.size(); ++i) {
            if (sign == 1) {
                temp = max(temp + arr[i], 1ll * arr[i]);
            } else {
                temp += -arr[i];
            }
            sign = -sign;
            result = max(result, temp);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    cout << max_plus_minus_sum(arr) << '\n';

    return 0;
}