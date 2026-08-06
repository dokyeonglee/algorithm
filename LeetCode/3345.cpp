class Solution {
public:
    int digit_product(int n) {
        int p = 1;
        while (n) {
            p *= n % 10;
            n /= 10;
        }
        return p;
    }

    int smallestNumber(int n, int t) {
        while (digit_product(n) % t) {
            ++n;
        }
        return n;
    }
};