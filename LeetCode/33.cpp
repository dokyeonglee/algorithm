class Solution {
public:
    int min_idx(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return mid + 1;
            }
            if (nums[mid] < nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] > nums.back()) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (nums.front() < nums.back()) {
            return 0;
        } else {
            return nums.size() - 1;
        }
    }
    int search(vector<int>& nums, int target) {
        int idx = min_idx(nums);
        auto it = lower_bound(nums.begin(), nums.begin() + idx, target);
        if (*it == target) {
            return it - nums.begin();
        }
        it = lower_bound(nums.begin() + idx, nums.end(), target);
        if (it != nums.end() && *it == target) {
            return it - nums.begin();
        }
        return -1;
    }
};