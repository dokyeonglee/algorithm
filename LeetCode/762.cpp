class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        const int bit = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7) 
                        | (1 << 11) | (1 << 13) | (1 << 17) | (1 << 19);

        int answer = 0;
        for (int i = left; i <= right; ++i) {
            if (bit & (1 << __builtin_popcount(i))) {
                ++answer;
            }
        }

        return answer;
    }
};