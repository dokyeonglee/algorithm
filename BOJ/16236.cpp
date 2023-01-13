#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};

pair<int, pair<int, int>> bfs(vector<vector<int>>& arr, pair<int, int>& src, int sz){

    vector<vector<bool>> visited(arr.size(), vector<bool>(arr.size()));
    visited[src.first][src.second] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, src));
    
    pair<int, int> result = make_pair(100, 100);
    int _cnt = 1e9;

    while(!q.empty()){
        int cnt = q.front().first;
        pair<int, int> now = q.front().second;
        q.pop();
        if(arr[now.first][now.second] != 0 and arr[now.first][now.second] < sz){
            if(cnt < _cnt){
                _cnt = cnt;
                result = now;
            }else if(cnt == _cnt){
                result = min(result, now);
            }
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr.size()){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] <=sz){
                visited[next_r][next_c] = true;
                q.push(make_pair(cnt + 1, make_pair(next_r, next_c)));
            }
        }
    }

    return make_pair(_cnt, result);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));
    pair<int, int> shark;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                shark = make_pair(i, j);
                arr[i][j] = 0;
            }
        }
    }

    int answer = 0;
    int sz = 2;
    int cnt = 0;

    while(1){

        auto result = bfs(arr, shark, sz);

        if(result.first == 1e9){
            break;
        }

        if(++cnt == sz){
            cnt = 0;
            sz++;
        }
        
        arr[result.second.first][result.second.second] = 0;
        answer += result.first;
        shark = result.second;

    }
    
    cout << answer;

    return 0;
}