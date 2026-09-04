class Solution {
public:
    bool check(vector<int>& data, int idx, int cnt) {
        if (idx + cnt >= data.size()) {
            return false;
        }

        for (int i = 1; i <= cnt; ++i) {
            if ((data[idx + i] >> 6) != 0b10) {
                return false;
            }
        }

        return true;
    }

    bool validUtf8(vector<int>& data) {
        int idx = 0;
        while (idx < data.size()) {
            int x = data[idx];
            int sz = 1;
            if ((x >> 5) == 0b110) {
                sz = 2;
            } else if ((x >> 4) == 0b1110) {
                sz = 3;
            } else if ((x >> 3) == 0b11110) {
                sz = 4;
            } else if (x >> 7) {
                return false;
            }

            if (!check(data, idx, sz - 1)) {
                return false;
            }

            idx += sz;
        }

        return true;
    }
};