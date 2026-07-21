class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int answer = 0;
        int cnt = 1;
        vector<int> zero_counts;

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i - 1]) {
                if (s[i] == '0') {
                    answer += cnt;
                } else {
                    zero_counts.push_back(cnt);
                }
                cnt = 1;
            } else {
                ++cnt;
            }
        }

        if (s.back() == '0') {
            zero_counts.push_back(cnt);
        } else {
            answer += cnt;
        }

        int add = 0;
        for (int i = 1; i < zero_counts.size(); ++i) {
            add = max(add, zero_counts[i] + zero_counts[i - 1]);
        }

        answer += add;

        return answer;
    }
};