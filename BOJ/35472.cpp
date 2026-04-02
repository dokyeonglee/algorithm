#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<pair<int, int>> dp(3, {2e9, 0});
    for (int i = 1; i <= n; ++i) {
        int x = 0;
        for (int j = 0; j < 3; ++j) {
            if (abs(arr[i] - dp[j].first) != 1) {
                x = max(x, dp[j].second);
            }
        }
        ++x;

        bool check = false;
        for (int j = 0; j < 3; ++j) {
            if (arr[i] == dp[j].first) {
                dp[j].second = x;
                check = true;
                break;
            }
        }

        if (!check) {
            dp.emplace_back(arr[i], x);
            dp.erase(min_element(dp.begin(), dp.end(), [](const pair<int, int>& a, const pair<int, int>& b){
                return a.second < b.second;
            }));
        }
    }

    int answer = 0;
    for (int i = 0; i < 3; ++i) {
        answer = max(answer, dp[i].second);
    }

    cout << answer;

    return 0;
}