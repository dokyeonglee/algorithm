class Solution {
public:
    bool hasAllCodes(string str, int k) {
        int n = str.size();
        if (n - k + 1 < (1 << k)) {
            return false;
        }

        int bit = 0;
        for (int i = 0; i < k; ++i) {
            if (str[i] == '1') {
                bit |= (1 << i);
            }
        }

        vector<bool> check(1 << k);
        check[bit] = true;

        int cnt = check.size() - 1;
        int msb = (1 << k-1);

        for (int i = k; i < n; ++i) {
            bit >>= 1;
            if (str[i] == '1') {
                bit |= msb;
            }
            if (!check[bit]) {
                check[bit] = true;
                --cnt;
            }
        }
        return cnt == 0;
    }
};
