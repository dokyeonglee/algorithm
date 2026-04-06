#include <iostream>
#include <queue>

using namespace std;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int dijkstra(const vector<vector<int>>& arr) {
    const int n = arr.size();
    vector<vector<int>> slopes(n, vector<int>(n, 1e9));
    slopes[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {0, 0}});

    while (!pq.empty()) {
        int current_slope = -pq.top().first;
        auto [r, c] = pq.top().second;
        pq.pop();

        if (slopes[r][c] < current_slope) {
            continue;
        }

        for (int i = 0; i < 4; ++i) {
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n) {
                continue;
            }
            int next_slope = max(current_slope, abs(arr[next_r][next_c] - arr[r][c]));
            if (slopes[next_r][next_c] > next_slope) {
                slopes[next_r][next_c] = next_slope;
                pq.push({-next_slope, {next_r, next_c}});
            }
        }
    }

    return slopes[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    cout << dijkstra(arr);

    return 0;
}