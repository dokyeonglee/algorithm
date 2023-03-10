#include <iostream>
#include <queue>

using namespace std;

int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};

int dd[][2] = {{}, {3, 4}, {3, 4}, {1, 2}, {1, 2}};

int bfs(vector<vector<int>>& arr, pair<int, pair<int, int>>& src, pair<int, pair<int, int>>& dst){

    vector<vector<vector<bool>>> visited(arr.size(), vector<vector<bool>>(arr[0].size(), vector<bool>(5)));
    visited[src.second.first][src.second.second][src.first] = true;

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, src.first), src.second));

    while(!q.empty()){
        int cnt = q.front().first.first;
        int dir = q.front().first.second;
        auto now = q.front().second;
        q.pop();
        if(dst.first == dir and dst.second == now){
            return cnt;
        }
        for(int i = 0; i < 2; i++){
            int next_dir = dd[dir][i];
            if(!visited[now.first][now.second][next_dir]){
                visited[now.first][now.second][next_dir] = true;
                q.push(make_pair(make_pair(cnt + 1, next_dir), now));
            }
        }
        for(int i = 1; i <= 3; i++){
            int next_r = now.first + dr[dir] * i;
            int next_c = now.second + dc[dir] * i;
            if(next_r < 1 or next_r >= arr.size() or next_c < 1 or next_c >= arr[0].size() or arr[next_r][next_c]){
                break;
            }
            if(!visited[next_r][next_c][dir]){
                visited[next_r][next_c][dir] = true;
                q.push(make_pair(make_pair(cnt + 1, dir), make_pair(next_r, next_c)));
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    pair<int, pair<int, int>> src;
    pair<int, pair<int, int>> dst;

    cin >> src.second.first >> src.second.second >> src.first;
    cin >> dst.second.first >> dst.second.second >> dst.first;

    cout << bfs(arr, src, dst);

    return 0;
}