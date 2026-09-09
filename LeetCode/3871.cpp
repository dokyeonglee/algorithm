class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        for (long long p = 1000; p <= n; p *= 1000) {
            commas += n - p + 1;
        }
        return commas;
    }
};