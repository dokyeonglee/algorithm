#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    ll abs_sum = 0;
    for (int i = 1; i <= n; ++i) {
        abs_sum += abs(arr[i]);
    }

    ll local_max = 0;
    ll global_max = 0;
    for (int i = 1; i <= n; ++i) {
        ll x = arr[i];
        if (arr[i] < 0) {
            x *= 3;
        }
        local_max = max(1ll * x, local_max + x);
        global_max = max(global_max, local_max);
    }

    cout << abs_sum + global_max;

    return 0;
}