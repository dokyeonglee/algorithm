constexpr int dr[] = {-1, 0, 1, 0};
constexpr int dc[] = {0, 1, 0, -1};

class Solution {
public:
    bool possible(const vector<vector<int>>& distance, int limit) {
        if (distance.front().front() < limit) {
            return false;
        }

        int n = distance.size();
        int m = distance[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m));
        visited[0][0] = true;

        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto now = q.front();
            q.pop();

            if (now.first == n - 1 && now.second == m - 1) {
                return true;
            }

            for (int i = 0; i < 4; ++i) {
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                
                if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                    continue;
                }

                if (!visited[next_r][next_c] && distance[next_r][next_c] >= limit) {
                    visited[next_r][next_c] = true;
                    q.emplace(next_r, next_c);
                }
            }

        }

        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if (grid.front().front() || grid.back().back()) {
            return 0;
        }

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> distance(n, vector<int>(m, -1));
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    distance[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        while (!q.empty()) {
            auto now = q.front();
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                
                if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                    continue;
                }

                if (distance[next_r][next_c] == -1) {
                    distance[next_r][next_c] = distance[now.first][now.second] + 1;
                    q.emplace(next_r, next_c);
                }
            }
        }

        int left = 0;
        int right = n + m;
        int answer = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(distance, mid)) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};