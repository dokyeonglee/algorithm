#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

ll squared_distance(const pair<int, int>& a, const pair<int, int>& b) {
    return 1ll * (a.first - b.first) * (a.first - b.first) + 1ll * (a.second - b.second) * (a.second - b.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;

    vector<pair<int, pair<int, int>>> moles(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> moles[i].second.first >> moles[i].second.second >> moles[i].first;
    }

    sort (moles.begin(), moles.end());

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (squared_distance(moles[i].second, moles[j].second) <= 1ll * s * (moles[i].first - moles[j].first) * s * (moles[i].first - moles[j].first)) {
                if (j == 0) {
                    dp[i] = max(dp[i], 1);
                } else if (dp[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << '\n';

    return 0;
}