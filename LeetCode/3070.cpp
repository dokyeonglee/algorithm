class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        if (grid[0][0] > k) {
            return 0;
        }

        int answer = 1;
        int c = grid[0].size();
        for (int i = 1; i < grid[0].size(); ++i) {
            grid[0][i] += grid[0][i - 1];
            if (grid[0][i] > k) {
                c = i;
                break;
            }
            ++answer;   
        }

        for (int i = 1; i < grid.size(); ++i) {
            grid[i][0] += grid[i - 1][0];
            if (grid[i][0] > k) {
                break;
            }
            ++answer;
            for (int j = 1; j < c; ++j) {
                grid[i][j] += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                if (grid[i][j] > k) {
                    c = j;
                    break;
                }
                ++answer;
            }
        }

        return answer;
    }
};