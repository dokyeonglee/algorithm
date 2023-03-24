#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(vector<vector<int>>& arr, vector<pair<int, int>>& manequin, int k){

    int n = arr.size();
    int m = arr[0].size();

    queue<pair<int, pair<int, int>>> q;

    for(int i = 0; i < manequin.size(); i++){
        q.push(make_pair(0, manequin[i]));
    }

    while(!q.empty()){

        int cnt = q.front().first;
        auto now = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }

            if(arr[next_r][next_c] != 3 and cnt < k){
                arr[next_r][next_c] = 3;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }

        }

    }

    return;

}

int bfs(vector<vector<int>>& arr, pair<int, int>& src){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[src.first][src.second] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, src));

    while(!q.empty()){

        int cnt = q.front().first;
        auto now = q.front().second;
        q.pop();

        if(arr[now.first][now.second] == 2){
            return cnt;
        }

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }

            if(!visited[next_r][next_c] and (arr[next_r][next_c] == 0 or arr[next_r][next_c] == 2)){
                visited[next_r][next_c] = true;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }

        }

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arr(n, vector<int>(m));

    vector<pair<int, int>> mannequin;
    pair<int, int> src;

    bool check = false;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2){
                check = true;
            }else if(arr[i][j] == 3){
                mannequin.push_back(make_pair(i, j));
            }else if(arr[i][j] == 4){
                src = make_pair(i, j);
            }
        }
    }

    if(!check){
        cout << -1;
        return 0;
    }

    bfs(arr, mannequin, k);

    cout << bfs(arr, src);

    return 0;
}