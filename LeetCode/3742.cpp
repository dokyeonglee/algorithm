class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        k = min(k, n + m);

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k + 2, -1e9)));
        dp[0][0][0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int cost = 0; cost <= k; ++cost) {
                    if (dp[i][j][cost] == -1e9) {
                        continue;
                    }
                    if (i + 1 < n) {
                        int next_score = dp[i][j][cost] + grid[i + 1][j];
                        int next_cost = (grid[i + 1][j] == 0 ? cost : cost + 1);
                        dp[i + 1][j][next_cost] =
                            max(dp[i + 1][j][next_cost], next_score);
                    }
                    if (j + 1 < m) {
                        int next_score = dp[i][j][cost] + grid[i][j + 1];
                        int next_cost = (grid[i][j + 1] == 0 ? cost : cost + 1);
                        dp[i][j + 1][next_cost] =
                            max(dp[i][j + 1][next_cost], next_score);
                    }
                }
            }
        }

        int result = -1;
        for (int i = 0; i <= k; ++i) {
            result = max(result, dp[n - 1][m - 1][i]);
        }

        return result;
    }
};