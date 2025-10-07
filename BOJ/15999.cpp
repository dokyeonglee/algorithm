#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int dr[] = {-1, 0, 1, 0};
constexpr int dc[] = {0, 1, 0, -1};

bool is_all_same(const vector<string>& grid, const int r, const int c) {
    const int n = grid.size();
    const int m = grid[0].size();

    for (int i = 0; i < 4; ++i) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
            continue;
        }

        if (grid[next_r][next_c] != grid[r][c]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }

    int answer = 1;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            if (is_all_same(grid, r, c)) {
                answer = 2 * answer % MOD;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}