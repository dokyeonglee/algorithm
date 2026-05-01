class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f_i = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            f_i += i * nums[i];
            sum += nums[i];
        }

        int answer = f_i;
        for (int i = n - 1; i > 0; --i) {
            f_i += sum - n * nums[i];
            answer = max(answer, f_i);
        }

        return answer;
    }
};