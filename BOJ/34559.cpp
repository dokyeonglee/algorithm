#include <iostream>
#include <queue>

using namespace std;

constexpr int dr[] = {-1, 0, 1, 0};
constexpr int dc[] = {0, 1, 0, -1};

vector<vector<int>> find_building(const vector<vector<char>>& arr) {
    const int n = arr.size() - 1;
    const int m = arr[0].size() - 1;

    vector<vector<int>> is_building(n + 1, vector<int>(m + 1, 1));
    is_building[1][1] = 0;

    queue<pair<int, int>> q;
    q.emplace(1, 1);

    while (!q.empty()) {
        auto [now_r, now_c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            const int next_r = now_r + dr[i];
            const int next_c = now_c + dc[i];

            if(next_r < 1 || next_r > n || next_c < 1 || next_c > m) {
                continue;
            }

            if (is_building[next_r][next_c] && arr[next_r][next_c] == '0') {
                is_building[next_r][next_c] = 0;
                q.emplace(next_r, next_c);
            }
        }
    }

    return is_building;
}

vector<vector<int>> build_prefix_sum(const vector<vector<int>>& is_building) {
    const int n = is_building.size() - 1;
    const int m = is_building[0].size() - 1;

    auto building_psum(is_building);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            building_psum[i][j] += building_psum[i][j - 1] + building_psum[i - 1][j] - building_psum[i - 1][j - 1];
        }
    }

    return building_psum;
}

int count_building(const vector<vector<int>>& building_psum, const int r1, const int c1, const int r2, const int c2) {
    return building_psum[r2][c2]
         - building_psum[r2][c1 - 1] 
         - building_psum[r1 - 1][c2]
         + building_psum[r1 - 1][c1 - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    auto is_building = find_building(arr);
    auto building_psum = build_prefix_sum(is_building);

    int q;
    cin >> q;

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        const int building_count = count_building(building_psum, r1, c1, r2, c2);
        if (building_count == 0) {
            cout << "Yes\n";
        } else {
            cout << "No " << building_count << '\n';
        }
    }


    return 0;
}