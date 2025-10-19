#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    if (n >= 1 && n <= 3) {
        cout << 1 << '\n';
        return 0;
    }

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    int diff_sum = (abs(arr[2] - arr[1]) == 1);

    for (int i = 3; i <= k; ++i) {
        dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + 1;
        diff_sum += (abs(arr[i] - arr[i - 1]) == 1);
    }

    if (diff_sum == k - 1) {
        dp[k] = 1;
    }

    k = max(k, 3);

    for (int i = k + 1; i <= n; ++i) {
        dp[i] = min(dp[i - 1], min(dp[i - 2], dp[i - 3])) + 1;
        diff_sum += (abs(arr[i] - arr[i - 1]) == 1);
        diff_sum -= (abs(arr[i - k + 1] - arr[i - k]) == 1);
        if (diff_sum == k - 1) {
            dp[i] = min(dp[i], dp[i - k] + 1);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}