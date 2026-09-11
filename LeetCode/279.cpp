class Solution {
public:
    int numSquares(int n) {
        int sqrt_n = sqrt(n);
        if (sqrt_n * sqrt_n == n) {
            return 1;
        }

        while (n % 4 == 0) {
            n /= 4;
        }
        if (n % 8 == 7) {
            return 4;
        }

        sqrt_n = sqrt(n);
        for (int i = 1; i <= sqrt_n; ++i) {
            int m = n - i * i;
            int sqrt_m = sqrt(m);
            if (sqrt_m * sqrt_m == m) {
                return 2;
            }
        }

        return 3;
    }
};