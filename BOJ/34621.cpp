#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 2e9;

void remove_snow(const vector<vector<int>>& snow, vector<int>& row_sum, vector<int>& col_sum, const int idx, const bool row_remove) {
    if (row_remove) {
        for (int i = 0; i < col_sum.size(); ++i) {
            col_sum[i] -= snow[idx][i];
        }
        row_sum[idx] = INF;
    } else {
        for (int i = 0; i < row_sum.size(); ++i) {
            row_sum[i] -= snow[i][idx];
        }
        col_sum[idx] = INF;
    }
}

int calculate_min_performance(const vector<vector<int>>& snow) {
    const int n = snow.size();
    const int m = snow[0].size();

    vector<int> row_sum(n);
    vector<int> col_sum(m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row_sum[i] += snow[i][j];
            col_sum[j] += snow[i][j];
        }
    }

    int min_performance = 0;

    for (int step = 0; step < n + m; ++step) {
        const int min_row = min_element(row_sum.begin(), row_sum.end()) - row_sum.begin();
        const int min_col = min_element(col_sum.begin(), col_sum.end()) - col_sum.begin();

        if (row_sum[min_row] < col_sum[min_col]) {
            min_performance = max(min_performance, row_sum[min_row]);
            remove_snow(snow, row_sum, col_sum, min_row, true);
        } else {
            min_performance = max(min_performance, col_sum[min_col]);
            remove_snow(snow, row_sum, col_sum, min_col, false);
        }
    }

    return min_performance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> snow(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> snow[i][j];
        }
    }

    cout << calculate_min_performance(snow) << '\n';

    return 0;
}