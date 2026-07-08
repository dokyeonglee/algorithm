class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    inline static int p[100001];
    inline static int init = []() {
        p[0] = 1;
        for (int i = 1; i < 100001; i++)
            p[i] = p[i - 1] * 10LL % MOD;
        return 0;
    }();

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> nums(s.size());
        vector<int> nonzero_cnt(s.size());
        vector<int> digit_sum(s.size());

        nums[0] = s[0] - '0';
        digit_sum[0] = s[0] - '0';
        nonzero_cnt[0] = (s[0] != '0');

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '0') {
                nums[i] = nums[i - 1];
            } else {
                nums[i] = (nums[i - 1] * 10ll + s[i] - '0') % MOD;
            }
            digit_sum[i] = digit_sum[i - 1] + s[i] - '0';
            nonzero_cnt[i] = nonzero_cnt[i - 1] + (s[i] != '0');
        }

        vector<int> answer;
        for (auto& q : queries) {
            if (q[0] == 0) {
                answer.push_back(1ll * nums[q[1]] * digit_sum[q[1]] % MOD);
            } else {
                long long temp = nums[q[0] - 1] * 1ll * p[nonzero_cnt[q[1]] - nonzero_cnt[q[0] - 1]] % MOD;
                long long num = (nums[q[1]] - temp + MOD) % MOD;
                answer.push_back(num * (digit_sum[q[1]] - digit_sum[q[0] - 1]) % MOD);
            }
        }

        return answer;
    }
};