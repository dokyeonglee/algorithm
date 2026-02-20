#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int l = max(0, i - k);
        int max_level = 0;
        for (int j = i; j > l; --j) {
            max_level = max(max_level, arr[j]);
            dp[i] = max(dp[i], dp[j - 1] + (i - j + 1) * max_level);
        }
    }

    cout << dp[n];

    return 0;
}