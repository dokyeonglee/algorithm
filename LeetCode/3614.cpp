class Solution {
public:
    char processStr(string s, long long k) {
        long long l = 0;
        vector<long long> lengths(s.size());
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c >= 'a' && c <= 'z') {
                ++l;
            } else if (c == '*') {
                l = max(0ll, l - 1);
            } else if (c == '#') {
                l <<= 1;
            }
            lengths[i] = l;
        }

        if (l <= k) {
            return '.';
        }

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (lengths[i] - 1 == k) {
                    return s[i];
                }
            } else if (s[i] == '#') {
                if (k >= lengths[i] / 2) {
                    k -= lengths[i] / 2;
                }
            } else if (s[i] == '%') {
                k = lengths[i] - 1 - k;
            }
        }

        return -1;      
    }
};