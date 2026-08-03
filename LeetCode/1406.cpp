class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1);

        dp[n - 1] = stoneValue[n - 1];
        if (n > 1) {
            dp[n - 2] = max(stoneValue[n - 2] - stoneValue[n - 1], stoneValue[n - 2] + stoneValue[n - 1]);
        }

        for (int i = n - 3; i >= 0; --i) {
            dp[i] = max(stoneValue[i] - dp[i + 1], stoneValue[i] + stoneValue[i + 1] - dp[i + 2]);
            dp[i] = max(dp[i], stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]);
        }

        if (dp[0] > 0) {
            return "Alice";
        } else if (dp[0] == 0) {
            return "Tie";
        } else {
            return "Bob";
        }
    }
};