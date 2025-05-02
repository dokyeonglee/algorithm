#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0, 0};
int dc[] = {0, 1, 0, -1, 0};

int bfs(vector<vector<int>>& arr){

    vector<vector<bool>> visited(305, vector<bool>(305));
    visited[0][0] = true;

    queue<pair<int, int>> q;
    q.emplace(0, 0);

    int result = 0;

    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            auto now = q.front();
            q.pop();
            if(arr[now.first][now.second] == 1e9){
                return result;
            }
            for(int i = 0; i < 4; i++){
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                if(next_r < 0 or next_r > 301 or next_c < 0 or next_c > 301){
                    continue;
                }
                if(!visited[next_r][next_c] and result + 1 < arr[next_r][next_c]){
                    visited[next_r][next_c] = true;
                    q.emplace(next_r, next_c);
                }
            }
        }
        result++;
    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> m;

    vector<vector<int>> arr(305, vector<int>(305, 1e9));

    while(m--){
        int c, r, t;
        cin >> c >> r >> t;
        for(int i = 0; i < 5; i++){
            int next_r = r + dr[i];
            int next_c = c + dc[i];
            if(next_r < 0 or next_r > 300 or next_c < 0 or next_c > 300){
                continue;
            }
            arr[next_r][next_c] = min(arr[next_r][next_c], t);
        }
    }

    cout << bfs(arr);

    return 0;

}