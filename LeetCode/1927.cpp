class Solution {
public:
    bool sumGame(string num) {
        const int sz = num.size() / 2;

        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < sz; ++i) {
            if (num[i] == '?') {
                ++cnt;
            } else {
                sum += num[i] - '0';
            }
        }

        for (int i = sz; i < num.size(); ++i) {
            if (num[i] == '?') {
                --cnt;
            } else {
                sum -= num[i] - '0';
            }
        }

        if (abs(cnt) % 2 == 1) {
            return true;
        }

        return sum + cnt / 2 * 9 != 0;
    }
};