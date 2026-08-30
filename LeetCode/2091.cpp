class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[left] > nums[i]) {
                left = i;
            }
            if (nums[right] < nums[i]) {
                right = i;
            }
        }

        if (left > right) {
            swap(left, right);
        }

        return min(right + 1, min(n - left, left + 1 + n - right));
    }
};