#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, n;
    cin >> h >> n;

    vector<pair<int, int>> students(n);
    for (auto& [height, speed] : students) {
        cin >> height >> speed;
    }

    vector<int> dp(h + 1);
    dp[0] = 1e9;
    for (auto& [height, speed] : students) {
        for (int i = h; i >= height; --i) {
            dp[i] = max(dp[i], min(dp[i - height], speed));
        }
    }

    cout << dp[h] << '\n';

    return 0;
}