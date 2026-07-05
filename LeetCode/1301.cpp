constexpr int dr[] = {0, -1, -1};
constexpr int dc[] = {-1, -1, 0};
constexpr int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        board[0][0] = '0';
        board[n - 1][m - 1] = '0';

        vector<vector<int>> max_score(n, vector<int>(m));
        vector<vector<int>> way(n, vector<int>(m));

        way[n - 1][m - 1] = 1;

        for (int r = n - 1; r >= 0; --r) {
            for (int c = m - 1; c >= 0; --c) {
                if (way[r][c] == 0) {
                    continue;
                }

                for (int k = 0; k < 3; ++k) {
                    int next_r = r + dr[k];
                    int next_c = c + dc[k];

                    if (next_r < 0 || next_c < 0 || board[next_r][next_c] == 'X') {
                        continue;
                    }

                    int score = max_score[r][c] + (board[next_r][next_c] - '0');

                    if (max_score[next_r][next_c] < score) {
                        max_score[next_r][next_c] = score;
                        way[next_r][next_c] = way[r][c];
                    } else if (max_score[next_r][next_c] == score){
                        way[next_r][next_c] = (way[next_r][next_c] + way[r][c]) % MOD;
                    }
                }
            }
        }

        return {max_score[0][0], way[0][0]};
    }
};