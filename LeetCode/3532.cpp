class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        int p = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                p = i;
            }
            parent[i] = p;
        }

        vector<bool> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            answer.push_back(parent[q[0]] == parent[q[1]]);
        }

        return answer;
    }
};