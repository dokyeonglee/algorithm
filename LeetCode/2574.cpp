class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int left_sum = 0;
        int right_sum = sum;
        vector<int> answer(nums.size());
        for (int i = 0; i < answer.size(); ++i) {
            right_sum -= nums[i];
            answer[i] = abs(left_sum - right_sum);
            left_sum += nums[i];
        }

        return answer;
    }
};