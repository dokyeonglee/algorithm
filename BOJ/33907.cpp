#include <iostream>
#include <vector>
#include <deque>

using namespace std;

constexpr int dr[] = {-1, 0, 1, 0};
constexpr int dc[] = {0, 1, 0, -1};
constexpr int INF = 1e9;

int min_spray_to_escape(const vector<vector<int>>& grid, const int risk_threshold, vector<vector<int>>& visited) {

    const int n = grid.size();
    const int m = grid[0].size();

    deque<pair<int, pair<int, int>>> dq;
    dq.emplace_front(0, make_pair(0, 0));
    visited[0][0] = risk_threshold;

    while (!dq.empty()) {
        int used_spray = dq.front().first;
        auto now = dq.front().second;
        dq.pop_front();

        if (now.first == n - 1 && now.second == m - 1) {
            return used_spray;
        }
        
        for (int i = 0; i < 4; ++i) {
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                continue;
            }
            if (visited[next_r][next_c] == risk_threshold) {
                continue;
            }

            visited[next_r][next_c] = risk_threshold;

            if (grid[next_r][next_c] <= risk_threshold) {
                dq.emplace_front(used_spray, make_pair(next_r, next_c));
            } else {
                dq.emplace_back(used_spray + 1, make_pair(next_r, next_c));
            }

        }
    }

    return INF;
}

int find_min_risk(const vector<vector<int>>& grid, const int spray_limit) {


    int left = 0;
    int right = INF;
    int min_risk = -1;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), -1));

    while (left <= right) {
        int mid = (left + right) / 2;
        int min_spray = min_spray_to_escape(grid, mid, visited);

        if (min_spray <= spray_limit) {
            min_risk = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return min_risk;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, spray_limit;
    cin >> n >> m >> spray_limit;

    vector<vector<int>> grid(n, vector<int>(m));
    for (auto& row : grid) {
        for (int& cell : row) {
            cin >> cell;
        }
    }

    cout << find_min_risk(grid, spray_limit) << '\n';

    return 0;
}