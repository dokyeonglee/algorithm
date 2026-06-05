class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int answer = 1e9;
        vector<pair<int, int>> indices(nums.size() + 1, {-1, -1});
        for (int i = 0; i < nums.size(); ++i) {
            auto& p = indices[nums[i]];
            if (p.first == -1) {
                p.first = i;
            } else if (p.second == -1) {
                p.second = i;
            } else {
                answer = min(answer, i - p.first);
                p.first = exchange(p.second, i);
            }
        }

        if (answer == 1e9) {
            answer = -1;
        } else {
            answer *= 2;
        }

        return answer;
    }
};