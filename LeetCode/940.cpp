class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int distinctSubseqII(string s) {
        int answer = 0;
        vector<int> last(26);
        for (char ch : s) {
            int idx = ch - 'a';
            int duplicate = (answer - last[idx] + MOD) % MOD;
            last[idx] = answer + 1;
            answer = (last[idx] + duplicate) % MOD;
        }
        return answer;
    }
};