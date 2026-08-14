class Solution {
public:
    int maximumLengthSubstring(string s) {
        int answer = 0;
        vector<int> cnt(26);

        int left = 0;
        int right = 0;

        while (right < s.size()) {
            int idx = s[right] - 'a';

            ++cnt[idx];
            while (cnt[idx] > 2) {
                --cnt[s[left++] - 'a'];
            }

            answer = max(answer, right - left + 1);
            ++right;
        }

        return answer;
    }
};