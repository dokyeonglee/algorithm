class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> prev(256, -1);
        int answer = 0;

        for (int left = 0, right = 0; right < s.size(); ++right) {
            if (prev[s[right]] != -1 && prev[s[right]] >= left) {
                left = prev[s[right]] + 1;
            } else {
                answer = max(answer, right - left + 1);
            }
            prev[s[right]] = right;
        }
        return answer;
    }
};