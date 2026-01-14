#include <iostream>
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& tree, const vector<int>& arr, vector<vector<int>>& dp, const int now) {
    for (const int next : tree[now]) {
        dfs(tree, arr, dp, next);
        dp[now][0] += max(dp[next][0], dp[next][1]);
    }

    for (const int next : tree[now]) {
        dp[now][1] = max(dp[now][1], dp[next][0]+ dp[now][0] - max(dp[next][0], dp[next][1]) + arr[now] * arr[next]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;

        tree[p].push_back(i);
    }

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dfs(tree, arr, dp, 1);

    cout << max(dp[1][0], dp[1][1]) << '\n';

    return 0;
}