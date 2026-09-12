class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5));
        for (int i = 0; i < n; ++i) {
            int idx = lower_bound(intervals.begin(), intervals.end(), intervals[i][0], 
                [](vector<int>& a, int target) {
                    return a[1] < target;
                }) - intervals.begin();

            for (int j = 1; j <= 4; ++j) {
                auto indices = dp[idx][j - 1].second;
                indices.push_back(intervals[i][3]);
                sort(indices.begin(), indices.end());
                pair<long long, vector<int>> take = {dp[idx][j - 1].first - intervals[i][2], indices};
                dp[i + 1][j] = min(dp[i][j], take);
            }
        }

        return dp[n][4].second;
    }
};