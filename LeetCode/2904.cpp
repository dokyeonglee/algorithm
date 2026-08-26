class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string answer;
        int left = 0;
        int right = 0;
        int cnt = 0;
        int min_len = INT_MAX;

        while (right < s.size()) {
            if (s[right] == '1') {
                ++cnt;
            }

            while (cnt == k) {
                int len = right - left + 1;
                if (len <= min_len){
                    string temp = s.substr(left ,len);
                    if (len == min_len) {
                        answer = min(answer, temp);
                    } else {
                        answer = temp;
                    }
                    min_len=len;
                }

                if (s[left++] == '1') {
                    --cnt;
                }
            }

            ++right;
        }

        return answer;
    }
};