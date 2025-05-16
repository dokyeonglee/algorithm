#include <iostream>
#include <queue>

using namespace std;

constexpr int INF = 1e8;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

void compute_distance(const vector<string>& school_map, const pair<int, int>& start, vector<vector<int>>& distance) {
    int n = school_map.size();
    int m = school_map[0].size();

    distance[start.first][start.second] = 0;

    queue<pair<int, int>> q;
    q.emplace(start);

    while (!q.empty()) {
        auto [now_r, now_c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = now_r + dr[i];
            int next_c = now_c + dc[i];

            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m || school_map[next_r][next_c] == '#') {
                continue;
            }

            if (distance[next_r][next_c] != INF) {
                continue;
            }

            distance[next_r][next_c] = distance[now_r][now_c] + 1;
            q.emplace(next_r, next_c);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pair<int, int> jinu;
    pair<int, int> seungchan;
    vector<string> school_map(n);
    vector<vector<int>> distance_from_jinu(n, vector<int>(m, INF));
    vector<vector<int>> distance_from_seungchan(n, vector<int>(m, INF));

    for (int i = 0; i < n; i++) {
        cin >> school_map[i];

        for (int j = 0; j < m; j++) {
            if (school_map[i][j] == 'J') {
                jinu = {i, j};
            } else if (school_map[i][j] == 'S') {
                seungchan = {i, j};
            }
        }
    }

    compute_distance(school_map, jinu, distance_from_jinu);
    compute_distance(school_map, seungchan, distance_from_seungchan);

    int answer = 2 * distance_from_jinu[seungchan.first][seungchan.second];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (school_map[i][j] == 'T') {
                const int jinu_to_teacher = 2 * distance_from_jinu[i][j];
                const int teacher_to_seungchan = distance_from_seungchan[i][j];
                answer = min(answer, jinu_to_teacher + teacher_to_seungchan);
            }
        }
    }

    if (answer >= INF) {
        answer = -1;
    }

    cout << answer;

    return 0;

}