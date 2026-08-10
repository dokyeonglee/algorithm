vector<bool> dp(1e5 + 1);

auto init = []() {
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i]) {
            continue;
        }
        for (int j = 1; i + j * j < dp.size(); j++) {
            dp[i + j * j] = true;
        }
    }
    return 0;
}();

class Solution {
public:
    bool winnerSquareGame(int n) {
        return dp[n];
    }
};