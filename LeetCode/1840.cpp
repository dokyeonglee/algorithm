class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end());
        restrictions.push_back({n, n - 1});

        int prev_id = 1;
        int prev_restriction = 0;
        for (int i = 0; i < restrictions.size(); ++i) {
            int id = restrictions[i][0];
            int& restriction = restrictions[i][1];
            restriction = min(restriction, prev_restriction + id - prev_id);
            prev_restriction = restriction;
            prev_id = id;
        }

        prev_id = n;
        prev_restriction = n - 1;
        for (int i = restrictions.size() - 1; i >= 0; --i) {
            int id = restrictions[i][0];
            int& restriction = restrictions[i][1];
            restriction = min(restriction, prev_restriction + prev_id - id);
            prev_restriction = restriction;
            prev_id = id;
        }

        prev_id = 1;
        prev_restriction = 0;
        int answer = min(restrictions[0][1], restrictions[0][0] - 1);
        for (int i = 0; i < restrictions.size(); ++i) {
            int id = restrictions[i][0];
            int& restriction = restrictions[i][1];
            answer = max(answer, (id - prev_id + restriction + prev_restriction) / 2);
            prev_restriction = restriction;
            prev_id = id;
        }

        return answer;
    }
};