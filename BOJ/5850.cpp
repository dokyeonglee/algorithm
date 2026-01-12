#include <iostream>
#include <queue>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int calculate_perimeter(const vector<vector<bool>> bales) {
    int perimeter = 0;

    vector<vector<bool>> visited(102, vector<bool>(102));
    visited[0][0] = true;

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        const auto [now_r, now_c] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            const int next_r = now_r + dr[i];
            const int next_c = now_c + dc[i];

            if (next_r < 0 || next_r > 101 || next_c < 0 || next_c > 101) {
                continue;
            }

            if (bales[next_r][next_c]) {
                ++perimeter;
            }

            if (!visited[next_r][next_c] && !bales[next_r][next_c]) {
                visited[next_r][next_c] = true;
                q.emplace(next_r, next_c);
            }
        }
    }
    
    return perimeter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<bool>> bales(102, vector<bool>(102));

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> r >> c;

        bales[r][c] = true;
    }

    cout << calculate_perimeter(bales) << '\n';

    return 0;
}