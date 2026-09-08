class Solution {
public:
    static bool is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    bool doesAliceWin(string s) {
        return any_of(s.begin(), s.end(), is_vowel);
    }
};