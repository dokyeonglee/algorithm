#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& a : arr) {
        cin >> a;
    }

    vector<int> dp(500, -1);
    dp[0] = 0;

    for (const int a : arr) {
        if (a > 500 && a < 20000) {
            vector<int> dp2(dp);
            for (int i = 0; i < 500; ++i) {
                if (dp[i] != -1) {
                    dp2[(dp[i] + a) % 500] = max(dp2[(dp[i] + a) % 500], dp[i] + a - 500);
                }
            }
            dp = dp2;
        }
    }

    cout << dp[0] << '\n';

    return 0;
}