#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr, pair<int, int>& red_src, pair<int, int>& blue_src, pair<int, int>& hole){

    vector<vector<vector<vector<int>>>> visited(arr.size(), vector<vector<vector<int>>>(arr[0].size(), vector<vector<int>>(arr.size(), vector<int>(arr[0].size()))));
    visited[red_src.first][red_src.second][blue_src.first][blue_src.second] = true;

    queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    q.push(make_pair(0, make_pair(red_src, blue_src)));

    while(!q.empty()){

        int cnt = q.front().first;
        auto red = q.front().second.first;
        auto blue = q.front().second.second;
        q.pop();

        if(red == hole){
            return cnt;
        }

        for(int i = 0; i < 4; i++){

            auto next_red = red;
            auto next_blue = blue;
            int cnt_red = 0;
            int cnt_blue = 0;

            while(arr[next_red.first + dr[i]][next_red.second + dc[i]] != '#' and next_red != hole){
                next_red.first += dr[i];
                next_red.second += dc[i];
                cnt_red++;
            }

            while(arr[next_blue.first + dr[i]][next_blue.second + dc[i]] != '#' and next_blue != hole){
                next_blue.first += dr[i];
                next_blue.second += dc[i];
                cnt_blue++;
            }

            if(next_red == hole and next_blue == hole){
                continue;
            }

            if(next_red == next_blue){
                if(cnt_red > cnt_blue){
                    next_red.first -= dr[i];
                    next_red.second -= dc[i];
                }else{
                    next_blue.first -= dr[i];
                    next_blue.second -= dc[i];
                }
            }

            if(next_blue == hole){
                continue;
            }

            if(cnt + 1 <= 10 and !visited[next_red.first][next_red.second][next_blue.first][next_blue.second]){
                visited[next_red.first][next_red.second][next_blue.first][next_blue.second] = true;
                q.push(make_pair(cnt + 1, make_pair(next_red, next_blue)));
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);
    pair<int, int> red_src;
    pair<int, int> blue_src;
    pair<int, int> hole;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'R'){
                red_src = make_pair(i, j);
                arr[i][j] = '.';
            }else if(arr[i][j] == 'B'){
                blue_src = make_pair(i, j);
                arr[i][j] = '.';
            }else if(arr[i][j] == 'O'){
                hole = make_pair(i, j);
            }
        }
    }

    cout << bfs(arr, red_src, blue_src, hole);

    return 0;
}