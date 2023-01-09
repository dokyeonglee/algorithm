#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int r, int c, int num){

    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    int _cnt = 0;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        arr[now.first][now.second] = num;
        _cnt++;

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 1 or next_r >= arr.size() - 1 or next_c < 1 or next_c >= arr[0].size() - 1){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] == 0){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    return _cnt;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= m; j++){
            arr[i][j] = str[j - 1] - '0';
        }
    }

    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2));
    
    int num = 2;
    vector<int> cnt(2);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!visited[i][j] and arr[i][j] == 0){
                cnt.push_back(bfs(arr, visited, i, j, num++));
            }
        }
    }

    vector<bool> check(cnt.size());

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(arr[i][j] != 1){
                cout << 0;
            }else{
                int result = 1;
                for(int k = 0; k < 4; k++){
                    int num = arr[i + dr[k]][j + dc[k]];
                    if(!check[num]){
                        check[num] = true;
                        result += cnt[num];
                    }
                }
                for(int k = 0; k < 4; k++){
                    int num = arr[i + dr[k]][j + dc[k]];
                    check[num] = false;
                }
                cout << result % 10;
            }
        }
        cout << "\n";
    }

    return 0;
}