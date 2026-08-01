class Solution {
public:
    int solve(const vector<int>& nums, vector<vector<int>>& dp, int x, int y) {
        if (x == y) {
            return nums[x];
        }

        int& ret = dp[x][y];
        if (ret != -1) {
            return ret;
        }

        int left = nums[x] - solve(nums, dp, x + 1, y);
        int right = nums[y] - solve(nums, dp, x, y - 1);

        return ret = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        if (nums.size() % 2 == 0) {
            return true;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        return solve(nums, dp, 0, nums.size() - 1) >= 0;
    }
};