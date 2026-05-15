class Solution {
public:
    int findMin(vector<int>& nums) {
       int min_element = min(nums.front(), nums.back());
       int left = 1;
       int right = nums.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid + 1] < nums[mid]) {
                return nums[mid + 1];
            }
            if (nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }
            if (nums.back() < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return min_element;
    }
};