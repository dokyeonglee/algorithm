class Solution {
public:
    bool check(vector<int>& nums) {
        int decrease_count = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                ++decrease_count;
            }
        }
        return decrease_count == 0 || (decrease_count == 1 && nums.front() >= nums.back());
    }
};