class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26);
        vector<bool> check(26);

        for (char c : s) {
            ++cnt[c - 'a'];
        }
    
        string answer;
        for (char c : s) {
            int idx = c - 'a';
            if (!check[idx]) {
                while (!answer.empty() && answer.back() > c && cnt[answer.back() - 'a']) {
                    check[answer.back() - 'a'] = false;
                    answer.pop_back();
                }
                check[idx] = true;
                answer += c;
            }
            --cnt[idx];
        }

        return answer;
    }
};