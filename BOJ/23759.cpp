#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_erase_count(const vector<string>& arr) {
    const int n = arr.size();
    const int k = arr[0].size();

    vector<vector<int>> dp(k, vector<int>(26));

    for (const auto& s : arr) {
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            best = max(best, dp[i][s[i] - 'a']);
        }
        for (int i = 0; i < s.size(); ++i) {
            dp[i][s[i] - 'a'] = best + 1;
        }
    }

    int max_remain = 0;
    for (const auto& row : dp) {
        max_remain = max(max_remain, *max_element(row.begin(), row.end()));
    }

    return n - max_remain;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> arr(n);
    for (auto& s : arr) {
        cin >> s;
    }

    cout << min_erase_count(arr) << '\n';

    return 0;
}