class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int answer = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int cnt = 0;
            for (int j = i; j < nums.size(); ++j) {
                if (nums[j] == target) {
                    ++cnt;
                }
                if (cnt > (j - i + 1) / 2) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};