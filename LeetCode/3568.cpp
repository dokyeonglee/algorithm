struct State {
    int r, c;
    int collected;
    int energy;
};

class Solution {
public:
    static constexpr int dr[] = {-1, 0, 1, 0};
    static constexpr int dc[] = {0, 1, 0, -1};

    int minMoves(vector<string>& classroom, int energy) {
        const int n = classroom.size();
        const int m = classroom[0].size();

        int r = -1;
        int c = -1;
        int cnt = 0;

        vector<vector<int>> litter_id(n, vector<int>(m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (classroom[i][j] == 'S') {
                    r = i;
                    c = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = cnt++;
                }
            }
        }

        if (cnt == 0) {
            return 0;
        }

        int all_collected = (1 << cnt) - 1;

        vector<vector<vector<int>>> max_energy(n, vector<vector<int>>(m, vector<int>(1 << cnt, -1)));
        max_energy[r][c][0] = energy;
        

        queue<State> q;
        q.emplace(r, c, 0, energy);

        for (int d = 0; !q.empty(); ++d) {
            int sz = q.size();
            while (sz--) {
                auto now = q.front();
                q.pop();

                if (now.collected == all_collected) {
                    return d;
                }

                if (now.energy == 0) {
                    continue;
                }

                for (int i = 0; i < 4; ++i) {
                    int next_r = now.r + dr[i];
                    int next_c = now.c + dc[i];

                    if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
                        continue;
                    }

                    if (classroom[next_r][next_c] == 'X') {
                        continue;
                    }

                    int next_energy = now.energy - 1;
                    int next_collected = now.collected;

                    if (litter_id[next_r][next_c] != -1) {
                        next_collected |= (1 << litter_id[next_r][next_c]);
                    }

                    if (classroom[next_r][next_c] == 'R') {
                        next_energy = energy;
                    }

                    if (max_energy[next_r][next_c][next_collected] < next_energy) {
                        max_energy[next_r][next_c][next_collected] = next_energy;
                        q.emplace(next_r, next_c, next_collected, next_energy);
                    }
                }
            }
        }

        return -1;
    }
};