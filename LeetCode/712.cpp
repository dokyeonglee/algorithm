class Solution {
public:
    int minimumDeleteSum(string& s1, string& s2) {
        if (s1.size() < s2.size()) {
            swap(s1, s2);
        }

        vector<vector<int>> dp(2, vector<int>(s2.size() + 1));
        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i & 1][j] = dp[i & 1 ^ 1][j - 1] + s1[i - 1];
                } else {
                    dp[i & 1][j] = max(dp[i & 1][j - 1], dp[i & 1 ^ 1][j]);
                }
            }
        }

        int ascii_sum = 0;
        for (int i = 0; i < s1.size(); ++i) {
            ascii_sum += s1[i];
        }
        for (int i = 0; i < s2.size(); ++i) {
            ascii_sum += s2[i];
        }

        return ascii_sum - 2 * dp[s1.size() & 1][s2.size()];
    }
};