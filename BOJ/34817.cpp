#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    int max_value = arr[0];
    int max_diff = 0;

    for (int i = 1; i < n; ++i) {
        max_diff = max(max_diff, max_value - arr[i]);
        max_value = max(max_value, arr[i]);
    }

    if (max_diff <= k) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}