class Solution {
public:
    int minimumPushes(string word) {
        vector<int> cnt(26);
        for (char c : word) {
            ++cnt[c - 'a'];
        }
      
        sort(cnt.rbegin(), cnt.rend());

        int answer = 0;
        for (int i = 0; i < 26 && cnt[i]; ++i) {
            answer += i / 8 + 1;
        }

        return answer;
    }
};