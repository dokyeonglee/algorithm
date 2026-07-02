constexpr int dr[4] = {-1, 0, 1, 0};
constexpr  int dc[4] = {0, 1, 0, -1};

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        distance[0][0] = grid[0][0];

        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);

        while (!dq.empty()) {
            auto [now_r, now_c] = dq.front();
            dq.pop_front();

            if (now_r == n - 1 && now_c == m - 1) {
                return distance[n - 1][m - 1] < health;
            }

            for (int i = 0; i < 4; ++i) {
                int next_r = now_r + dr[i];
                int next_c = now_c + dc[i];

                if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                    continue;
                }

                if (distance[now_r][now_c] + grid[next_r][next_c] < distance[next_r][next_c]) {
                    distance[next_r][next_c] = distance[now_r][now_c] + grid[next_r][next_c];
                    if (grid[next_r][next_c] == 0) {
                        dq.emplace_front(next_r, next_c);
                    } else {
                        dq.emplace_back(next_r, next_c);
                    }
                }
            }
        }

        return distance.back().back() < health;
    }
};