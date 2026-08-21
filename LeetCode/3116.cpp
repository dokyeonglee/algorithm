class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        const long long max_value = (long long)coins[0] * k;
        const int n = coins.size();
        vector<long long> signed_lcm(1 << n);
        for (int i = 1; i < (1 << n); ++i) {
            long long x = 1;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    x = lcm(x, coins[j]);
                    if (max_value < x) {
                        break;
                    }
                }
            }
            if (__builtin_popcount(i) % 2) {
                signed_lcm[i] = x;
            } else {
                signed_lcm[i] = -x;
            }
        }

        long long left = 1;
        long long right = max_value;
        long long answer = right;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long cnt = 0;
            for (int i = 1; i < signed_lcm.size(); ++i) {
                cnt += mid / signed_lcm[i];
            }
            if (cnt >= k) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }
};