#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr, pair<int, int>& src, pair<int, int>& dst, int k){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 987654321));
    visited[src.first][src.second] = 0;

    queue<pair<int, int>> q;
    q.push(src);

    while(!q.empty()){
        
        int sz = q.size();

        for(int x = 0; x < sz; x++){
            auto now = q.front();
            q.pop();
            if(now == dst){
                return visited[now.first][now.second];
            }
            for(int j = 0; j < 4; j++){
                for(int i = 1; i <= k; i++){
                    int next_r = now.first + dr[j] * i;
                    int next_c = now.second + dc[j] * i;
                    if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m or arr[next_r][next_c] == '#' or visited[next_r][next_c] <= visited[now.first][now.second]){
                        break;
                    }
                    if(visited[next_r][next_c] == 987654321){
                        visited[next_r][next_c] = visited[now.first][now.second] + 1;
                        q.push(make_pair(next_r, next_c));
                    }
                }
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

    vector<string> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    pair<int, int> src, dst;
    cin >> src.first >> src.second >> dst.first >> dst.second;

    src.first--;
    src.second--;
    dst.first--;
    dst.second--;

    cout << bfs(arr, src, dst, k);

    return 0;
}