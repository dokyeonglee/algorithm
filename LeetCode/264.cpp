    class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> dp(n + 1);
            dp[1] = 1;

            int idx1 = 1;
            int idx2 = 1;
            int idx3 = 1;


            for (int i = 2; i <= n; ++i) {
                int next1 = dp[idx1] * 2;
                int next2 = dp[idx2] * 3;
                int next3 = dp[idx3] * 5;

                dp[i] = min({next1, next2, next3});

                if (dp[i] == next1) {
                    idx1++;
                }
                if (dp[i] == next2) {
                    idx2++;
                }
                if (dp[i] == next3) {
                    idx3++;
                }
            }

            return dp[n];
        }
    };