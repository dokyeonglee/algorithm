#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> arr(k + 1);
    for (int i = 1; i <= k; ++i) {
        cin >> arr[i];
    }

    vector<double> dp(k + 1);
    dp[0] = n;

    for (int i = 1; i <= k; ++i) {
        dp[i] = (1 - (double)arr[i] / n) * dp[i - 1] + (double)arr[i] / n * (n - dp[i - 1]);
    }

    cout << fixed;
    cout.precision(10);
    cout << dp[k] << '\n';

    return 0;
}