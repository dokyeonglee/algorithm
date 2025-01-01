#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, pair<int, int>& src, int c){

    int n = arr.size();
    int m = arr[0].size();

    int dist = 0;
    int psum = arr[src.first][src.second];
    int result = arr[src.first][src.second];

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[src.first][src.second] = true;

    queue<pair<int, int>> q;
    q.emplace(src);
    

    while(!q.empty()){
        int sz = q.size();
        dist++;
        while(sz--){
            auto now = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m or arr[next_r][next_c] == -1){
                    continue;
                }
                if(!visited[next_r][next_c]){
                    psum += arr[next_r][next_c];
                    visited[next_r][next_c] = true;
                    q.emplace(next_r, next_c);
                }
            }
        }
        result = max(result, psum - dist * c);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    pair<int, int> src;
    cin >> src.first >> src.second;

    src.first--;
    src.second--;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    cout <<  bfs(arr, src, c);

    return 0;

}