class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> prefix(stones);
        for (int i = 1; i < stones.size(); ++i) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int answer = prefix.back();
        for (int i = prefix.size() - 2; i > 0; --i) {
            answer = max(answer, prefix[i] - answer);
        }

        return answer;
    }
};