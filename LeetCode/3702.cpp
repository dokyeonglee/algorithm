class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool check = true;
        int x = 0;
        for (int num : nums) {
            if (num) {
                check = false;
            }
            x ^= num;
        }

        if (check) {
            return 0;
        }

        return nums.size() - (x == 0);
    }
};