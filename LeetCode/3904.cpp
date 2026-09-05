class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> prefix_max(nums);
        for (int i = 1; i < nums.size(); ++i) {
            prefix_max[i] = max(prefix_max[i], prefix_max[i - 1]);
        }

        int answer = -1;
        int suffix_min = INT_MAX;
        for (int i = nums.size() - 1; i >= 0; --i) {
            suffix_min = min(suffix_min, nums[i]);
            if (prefix_max[i] - suffix_min <= k) {
                answer = i;
            }
        }

        return answer;
    }
};