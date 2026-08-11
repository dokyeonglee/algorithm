class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<long long> dp(3);

        dp[0] = nums[0];
        dp[1] = max(nums[0] + nums[1], nums[0] - nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i % 3] = max(nums[i] + dp[(i - 1) % 3], nums[i - 1] - nums[i] + dp[(i - 2) % 3]);
        }

        return dp[(nums.size() - 1) % 3];
    }
};