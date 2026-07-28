class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for (int i = 0; i < s.size() / 2; ++i) {
            ++cnt[s[i] - 'a'];
        }

        int idx = 0;
        string answer(s);
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                answer[idx++] = 'a' + i;
            }
        }

        for (int i = idx; i < s.size(); ++i) {
            answer[i] = answer[s.size() - 1 - i];
        }

        return answer;
    }    
};