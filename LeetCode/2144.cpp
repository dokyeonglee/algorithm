class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());

        int answer = 0;
        for (int i = cost.size() - 1; i > 1; i -= 3) {
            answer += cost[i] + cost[i - 1];
        }

        if (cost.size() % 3 == 1) {
            answer += cost[0];
        } else if (cost.size() % 3 == 2) {
            answer += cost[0] + cost[1];
        }

        return answer;
    }
};