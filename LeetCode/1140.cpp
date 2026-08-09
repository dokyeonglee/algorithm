class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffix(piles);
        for (int i = piles.size() - 2; i >= 0; --i) {
            suffix[i] += suffix[i + 1];
        }
        return solve(suffix, dp, 0, 1);
    }

    int solve(const vector<int>& suffix, vector<vector<int>>& dp, int idx, int m) {
        if (idx + 2 * m >= suffix.size()) {
            return suffix[idx];
        }

        auto& ret = dp[idx][m];
        if (ret != -1) {
            return ret;
        }

        int opponent = INT_MAX;
        for (int i = 1; i <= 2 * m; ++i) {
            opponent = min(opponent, solve(suffix, dp, idx + i, max(m, i)));
        }

        return ret = suffix[idx] - opponent;
    }
};