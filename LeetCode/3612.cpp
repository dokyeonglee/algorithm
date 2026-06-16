class Solution {
public:
    string processStr(string s) {
        string answer;
        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                answer += c;
            } else if (c == '*') {
                if (answer.size() > 0) {
                    answer.pop_back();
                } 
            }else if (c == '#') {
                answer += answer;
            } else if (c == '%') {
                reverse(answer.begin(), answer.end());
            }
        }
        return answer;
    }
};