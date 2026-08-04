class Solution {
public:
    static constexpr int dr[] = {-1, 0, 1, 0};
    static constexpr int dc[] = {0, 1, 0, -1};

    void bfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;

        queue<pair<int, int>> q;
        q.emplace(r, c);

        while (!q.empty()) {
            auto now = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];

                if (next_r < 0 || next_r >= grid.size() || next_c < 0 || next_c >= grid[0].size()) {
                    continue;
                }

                if (!visited[next_r][next_c] && grid[next_r][next_c] == '1') {
                    visited[next_r][next_c] = true;
                    q.emplace(next_r, next_c);
                }
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ++answer;
                    bfs(grid, visited, i, j);
                }
            }
        }

        return answer;
    }
};