#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& dp, int n, int l) {
    if (l == 1) {
        return n == 1;
    }

    int& ret = dp[n][l];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    for (int i = 1; i * i < n; ++i) {
        ret += solve(dp, i, l - 1);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<vector<int>> dp(70001, vector<int>(6, -1));

    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        int answer = 0;
        if (l <= 5) {
            answer = solve(dp, n, l);
        }

        cout << answer << '\n';
    }

    return 0;
}