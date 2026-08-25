class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());    

        vector<int> now{intervals[0]};
        vector<vector<int>> answer;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= now[1]) {
                now[1] = max(now[1], intervals[i][1]);
            } else {
                answer.emplace_back(now);
                now = intervals[i];
            }
        }

        answer.emplace_back(now);

        return answer;
    }
};