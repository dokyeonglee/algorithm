class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int max_num = 0;
        vector<int> prefix_gcd(nums.size());

        for (int i = 0; i < n; ++i) {
            max_num = max(max_num, nums[i]);
            prefix_gcd[i] = gcd(max_num, nums[i]);
        }

        sort(prefix_gcd.begin(), prefix_gcd.end());

        int left = 0;
        int right = n - 1;
        long long answer = 0;
        while (left < right) {
            answer += gcd(prefix_gcd[left++], prefix_gcd[right--]);
        }

        return answer;
    }
};