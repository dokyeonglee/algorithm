class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= m * n;

        if (k == 0) {
            return grid;
        }

        vector<vector<int>> answer(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int c = j + k % n;
                int r = (i + k / n + c / n) % m;
                c %= n;
                answer[r][c] = grid[i][j];
            }
        }

        return answer;
    }
};