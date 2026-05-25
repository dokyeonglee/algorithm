class Solution {
private:
public:
    bool canReach(string s, int min_jump, int max_jump) {
        if (s.back() == '1') {
            return false;
        }

        const int n = s.size();
        if (max_jump == n - 1) {
            return true;
        }

        vector<int> psum(n);
        for (int i = 0; i < min_jump; ++i) {
            psum[i] = 1;
        }

        vector<bool> dp(n);
        for (int i = min_jump; i <= max_jump; ++i) {
            if (s[i] == '0' && psum[i - min_jump] > 0) {
                dp[i] = true;
            }
            psum[i] = psum[i - 1] + dp[i];
        }

        for (int i = max_jump + 1; i < n; ++i) {
            if (s[i] == '0' && psum[i - min_jump] - psum[i - max_jump - 1] > 0) {
                dp[i] = true;
            }
            psum[i] = psum[i - 1] + dp[i];
        }

        return dp.back();    
    }
};