class Solution {
public:
    long long sumAndMultiply(int n) {
        long long answer = 0;
        int digit_sum = 0;
        int p = 1;

        while (n) {
            int d = n % 10;
            if (d) {
                answer += d * p;
                digit_sum += d;
                p *= 10;
            }
            n /= 10;
        }

        answer *= digit_sum;

        return answer;
    }
};