class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });

        int effort = tasks[0][1] - tasks[0][0];
        for (int i = 0; i < tasks.size(); ++i) {
            effort = max(effort + tasks[i][0], tasks[i][1]);
        }

        return effort;
    }
};