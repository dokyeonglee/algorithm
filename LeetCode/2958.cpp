class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> cnt;

        int left = 0;
        int right = 0;
        int answer = 0;

        while (right < n) {
            ++cnt[nums[right]];
            while (cnt[nums[right]] > k) {
                --cnt[nums[left++]];
            }
            answer = max(answer, right - left + 1);
            ++right;
        }

        return answer;
    }
};