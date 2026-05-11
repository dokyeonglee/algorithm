class Solution {
public:
    string getHappyString(int n, int k) {
        int x = (1 << (n - 1));
        if (3 * x < k) {
            return "";
        }

        string str;
        if (k <= x) {
            str += 'a';
        } else if (k <= 2 * x) {
            str += 'b';
            k -= x;
        } else {
            str += 'c';
            k -= 2 * x;
        }

        x >>= 1;

        while (x > 0) {
            if (k <= x) {
                if (str.back() == 'a') {
                    str += 'b';
                } else {
                    str += 'a';
                }
            } else {
                if (str.back() == 'c') {
                    str += 'b';
                } else {
                    str += 'c';
                }
                k -= x;
            }

            x >>= 1;
        }

        return str;
    }
};