class Solution {
public:
    bool is_palindrome(string& s, int left, int right) {
        if (right >= s.size()) {
            return false;
        }
        while (left <= right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        if (k == 1) {
            return s.size();
        }

        int palindromes = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (is_palindrome(s, i, i + k - 1)) {
                ++palindromes;
                i += k - 1;
            } else if (is_palindrome(s, i, i + k)) {
                ++palindromes;
                i += k;
            }
        }

        return palindromes;
    }
};