class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long answer = 0;
        int sum = 0;
        int x = nums.size();
        vector<int> cnt(2 * x + 1);
        ++cnt[x];
        for (int num : nums) {
            if (num == target) {
                sum += cnt[x++];
                ++cnt[x];
            } else {
                sum -= cnt[--x]++;
            }
            answer += sum;
        }

        return answer;
    }
};