class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<int> row_count(grid.size());
        vector<int> col_count(grid[0].size());

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j  < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    ++row_count[i];
                    ++col_count[j];
                }
            }
        }

        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j  < grid[0].size(); ++j) {
                if (grid[i][j] && (row_count[i] > 1 || col_count[j] > 1)) {
                    ++answer;
                }
            }
        }

        return answer;
    }
};