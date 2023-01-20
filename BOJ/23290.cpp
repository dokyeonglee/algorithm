#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int priority[] = {2, 0, 6, 4};

bool in_range(int r, int c){
    return r >= 0 and r < 4 and c >= 0 and c < 4;
}

vector<vector<vector<int>>> copy_fish(vector<vector<vector<int>>>& arr){
    return arr;
}

void fish_move(vector<vector<vector<int>>>& arr, vector<vector<int>>& smell, pair<int, int>& shark){

    vector<vector<vector<int>>> cnt(4, vector<vector<int>>(4, vector<int>(8)));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                cnt[i][j][k] = arr[i][j][k];
            }
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int x = 0; x < 8; x++){

                if(cnt[i][j][x] == 0) continue;

                auto next = make_pair(i, j);
                int d = x;

                for(int k = x, y = 0; y < 8; k = (k + 7) % 8, y++){
                    int next_r = i + dr[k];
                    int next_c = j + dc[k];
                    if(in_range(next_r, next_c) and !(shark.first == next_r and shark.second == next_c) and smell[next_r][next_c] == 0){
                        next = make_pair(next_r, next_c);
                        d = k;
                        break;
                    }
                }

                arr[i][j][x] -= cnt[i][j][x];
                arr[next.first][next.second][d] += cnt[i][j][x];
            }
        }
    }
}

void shark_move(vector<vector<vector<int>>>& arr, vector<vector<int>>& smell, pair<int, int>& shark){

    pair<int, int> next;
    int max_fish = -1;
    set<pair<int, int>> path;

    for(int i = 0; i < 4; i++){

        int next_r = shark.first + dr[priority[i]];
        int next_c = shark.second + dc[priority[i]];

        if(!in_range(next_r, next_c)){
            continue;
        }

        for(int j = 0; j < 4; j++){

            int next_r2 = next_r + dr[priority[j]];
            int next_c2 = next_c + dc[priority[j]];

            if(!in_range(next_r2, next_c2)){
                continue;
            }

            for(int k = 0; k < 4; k++){

                int next_r3 = next_r2 + dr[priority[k]];
                int next_c3 = next_c2 + dc[priority[k]];

                if(!in_range(next_r3, next_c3)){
                    continue;
                }

                int cnt = 0;

                set<pair<int, int>> s;
                s.insert(make_pair(next_r, next_c));
                s.insert(make_pair(next_r2, next_c2));
                s.insert(make_pair(next_r3, next_c3));

                for(auto p : s){
                    for(int x = 0; x < 8; x++){
                        cnt += arr[p.first][p.second][x];
                    }
                }

                if(cnt > max_fish){
                    max_fish = cnt;
                    next = make_pair(next_r3, next_c3);
                    path = s;
                }
            }

        }
    }

    shark = next;

    for(auto p : path){
        for(int x = 0; x < 8; x++){
            if(arr[p.first][p.second][x]){
                arr[p.first][p.second][x] = 0;
                smell[p.first][p.second] = 3;
            }
        }
    }
}

void paste(vector<vector<vector<int>>>& arr, vector<vector<vector<int>>>& copied_fish){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                arr[i][j][k] += copied_fish[i][j][k];
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<vector<int>>> arr(4, vector<vector<int>>(4, vector<int>(8)));
    vector<vector<int>> smell(4, vector<int>(4));

    int m, s;
    cin >> m >> s;

    int r, c, d;

    for(int i = 1; i <= m; i++){
        cin >> r >> c >> d;
        arr[r - 1][c - 1][d - 1]++;
    }

    cin >> r >> c;

    pair<int, int> shark = make_pair(r - 1, c - 1);

    for(int i = 0; i < s; i++){
        auto copied_fish = copy_fish(arr);
        fish_move(arr, smell, shark);
        shark_move(arr, smell, shark);
        paste(arr, copied_fish);
        for(int r = 0; r < 4; r++){
            for(int c = 0; c < 4; c++){
                if(smell[r][c] > 0){
                    smell[r][c]--;
                }
            }
        }
    }

    int answer = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 8; k++){
                answer += arr[i][j][k];
            }
        }
    }

    cout << answer;

    return 0;
}