#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, int K){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(K + 1)));
    visited[0][0][0] = 1;

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));

    while(!q.empty()){
        int k = q.front().first;
        auto now = q.front().second;
        q.pop();
        if(now.first == n - 1 and now.second == m - 1){
            return visited[now.first][now.second][k];
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            int next_k = k + arr[next_r][next_c];
            if(next_k <= K and !visited[next_r][next_c][next_k]){
                visited[next_r][next_c][next_k] = visited[now.first][now.second][k] + 1;
                q.push(make_pair(next_k, make_pair(next_r, next_c)));
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
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j] - '0';
        }
    }

    cout << bfs(arr, k);

    return 0;
}