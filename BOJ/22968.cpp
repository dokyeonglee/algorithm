#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> dp(43);
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= 42; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + 1;
    }

    int t;
    cin >> t;

    while (t--) {
        int v;
        cin >> v;

        cout << upper_bound(dp.begin(), dp.end(), v) - dp.begin() - 1 << '\n';
    }

    return 0;
}