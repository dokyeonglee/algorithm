class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib(46);
        fib[0] = 1;
        fib[1] = 1;

        for (int i = 2; i <= 45; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        auto it = upper_bound(fib.begin(), fib.end(), k) - fib.begin();

        int answer = 0;
        for (int i = it; i >= 0; --i) {
            if (k >= fib[i]) {
                ++answer;
                k -= fib[i];
            }
        }

        return answer;
    }
};