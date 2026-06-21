class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cnt(1e5 + 1);
        for (int i = 0; i < costs.size(); ++i) {
            ++cnt[costs[i]];
        }
        int answer = 0;
        for (int i = 1; i < cnt.size() && i <= coins; ++i) {
            if (cnt[i]) {
                answer += min(cnt[i], coins / i);
                coins -= min(cnt[i], coins / i) * i;
            }
        }
        return answer;
    }
};