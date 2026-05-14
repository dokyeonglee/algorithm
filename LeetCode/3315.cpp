class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] % 2 == 0) {
                ans[i] = -1;
            } else {
                int x = (nums[i] + 1) >> 1;
                ans[i] = nums[i] ^ (x & -x);
            }
        }
        return ans;
    }
};