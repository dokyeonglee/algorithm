class Solution {
public:
    const int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        vector<vector<int>> dp(201, vector<int>(201));
        dp[0][0] = 1;

        for (int& num : nums) {
            vector<vector<int>> dp2(201, vector<int>(201));

            for (int i = 0; i <= 200; ++i) {
                int g1 = gcd(num, i);
                for (int j = 0; j <= 200; ++j) {
                    if (dp[i][j]) {
                        int g2 = gcd(num, j);
                        dp2[i][j] = (dp2[i][j] + dp[i][j]) % MOD;
                        dp2[g1][j] = (dp2[g1][j] + dp[i][j]) % MOD;
                        dp2[i][g2] = (dp2[i][g2] + dp[i][j]) % MOD;
                    }
                }
            }

            dp = move(dp2);
        }

        int answer = 0;
        for (int i = 1; i <= 200; ++i) {
            answer = (answer + dp[i][i]) % MOD;
        }

        return answer;
    }
};