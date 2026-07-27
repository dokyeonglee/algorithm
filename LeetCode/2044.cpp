class Solution {
public:
    int dfs(const vector<int>& nums, int max_or, int idx, int now) {
        if (idx == nums.size()) {
            return max_or == now;
        }
        if (now == max_or) {
            return 1 << (nums.size() - idx);
        }
        return dfs(nums, max_or, idx + 1, now) + dfs(nums, max_or, idx + 1, now | nums[idx]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int num : nums) {
            max_or |= num;
        }
        return dfs(nums, max_or, 0, 0);
    }
};