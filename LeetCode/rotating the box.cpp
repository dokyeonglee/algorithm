class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> rotated(m, vector<char>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rotated[i][j] = boxGrid[n - 1 - j][i];
            }
        }

        for (int j = 0; j < n; ++j) {
            int bottom = m - 1;
            for (int i = m - 1; i >= 0; --i) {
                if (rotated[i][j] == '#') {
                    swap(rotated[i][j], rotated[bottom][j]);
                    --bottom;
                } else if (rotated[i][j] == '*') {
                    bottom = i - 1;
                }
            }
        }

        return rotated;
    }
};