#include <iostream>
#include <vector>

using namespace std;

int find_best_knapsack(const vector<pair<int, int>>& items, const vector<int>& knapsacks) {
    vector<int> dp(1000001);

    for (const auto [w, v] : items) {
        for (int i = 1000000; i >= w; --i) {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }

    int best_knapsack = 0;
    for (int i = 1; i < knapsacks.size(); ++i) {
        if (1ll * dp[knapsacks[best_knapsack]] * knapsacks[i] < 1ll * knapsacks[best_knapsack] * dp[knapsacks[i]]) {
            best_knapsack = i;
        }
    }

    return best_knapsack + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> items(n);
    for (auto& [w, v] : items) {
        cin >> w >> v;
    }

    vector<int> knapsacks(m);
    for (int& knapsack : knapsacks) {
        cin >> knapsack;
    }

    cout << find_best_knapsack(items, knapsacks) << '\n';

    return 0;
}