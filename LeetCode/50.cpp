class Solution {
public:
    double myPow(double x, int n) {
        long long abs_n = abs((long long)n);
        double result = 1;
        while (abs_n > 0) {
            if (abs_n & 1) {
                result *= x;
            }
            x *= x;
            abs_n >>= 1;
        }

        if (n < 0) {
            result = 1 / result;
        }

        return result;
    }
};