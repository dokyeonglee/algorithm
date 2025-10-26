#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (1) {
        int n;
        double budget;

        cin >> n >> budget;

        if (n == 0) {
            break;
        }

        vector<pair<int, int>> candies(n);
        for (int i = 0; i < n; ++i) {
            int cal;
            double price;
            cin >> cal >> price;

            candies[i] = {cal, (int)(price * 100 + 0.5)};
        }

        const int int_budget = (int)(budget * 100 + 0.5);
        vector<int> dp(int_budget + 1);

        for (const auto [cal, int_price] : candies) {
            for (int j = int_price; j <= int_budget; ++j) {
                dp[j] = max(dp[j], dp[j - int_price] + cal);
            }
        }

        cout << dp[int_budget] << '\n';
    }

    return 0;
}