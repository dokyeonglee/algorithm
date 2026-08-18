class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> cnt(51);
        for (int num : nums) {
            ++cnt[num];
        }

        if (k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }

        if (k == 1) {
            int max_num = -1;
            for (int num : nums) {
                if (cnt[num] == 1) {
                    max_num = max(max_num, num);
                }
            }
            return max_num;
        }

        if (nums[0] == nums.back() || (cnt[nums[0]] > 1 && cnt[nums.back()] > 1)) {
            return -1;
        }

        if (cnt[nums[0]] == 1 && cnt[nums.back()] == 1) {
            return max(nums[0], nums.back());
        }

        if (cnt[nums.back()] == 1) {
            return nums.back();
        }

        return nums[0];
    }
};