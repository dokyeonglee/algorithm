class Solution {
public:
    bool is_good(int x) {
        bool good = false;
        while (x > 0) {    
            int d = x % 10;
            if (d == 3 || d == 4 || d == 7) {
                return false;
            }
            if (d == 2 || d == 5 || d == 6 || d == 9) {
                good = true;
            }
            x /= 10;
        }
        return good;
    }
    int rotatedDigits(int n) {
        int answer = 0;
        for (int i = 1; i <= n; ++i) {
            answer += is_good(i);
        }
        return answer;
    }
};