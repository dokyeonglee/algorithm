class Solution {
public:
    int digit_sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        int min_digit_sum = INT_MAX;
        for (int num : nums) {
            min_digit_sum = min(min_digit_sum, digit_sum(num));
        }
        return min_digit_sum;
    }
};