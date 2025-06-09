#include <iostream>
#include <vector>
#include <climits>

using namespace std;
using ll = long long;

enum Color {
    WHITE = 0,
    BLACK = 1
};

ll calculate_max_score(const vector<vector<int>>& board, const vector<vector<int>>& color) {

    const int n = board.size() - 1;
    const int m = board[0].size() - 1;

    vector<vector<ll>> min_dp(n + 1, vector<ll>(m + 1, LLONG_MAX));
    vector<vector<ll>> max_dp(n + 1, vector<ll>(m + 1, LLONG_MIN));

    min_dp[0][1] = 0;
    max_dp[0][1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            ll prev_max = max(max_dp[i][j - 1], max_dp[i - 1][j]) + board[i][j];
            ll prev_min = min(min_dp[i][j - 1], min_dp[i - 1][j]) + board[i][j];

            if (color[i][j] == BLACK) {
                min_dp[i][j] = -prev_max;
                max_dp[i][j] = -prev_min;
            } else {
                min_dp[i][j] = prev_min;
                max_dp[i][j] = prev_max;
            }
        }
    }

    return max_dp[n][m];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> board(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> board[i][j];
        }
    }

    vector<vector<int>> color(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> color[i][j];
        }
    }

    cout << calculate_max_score(board, color) << '\n';

    return 0;
}