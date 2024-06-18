#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, int m){

    int n = arr.size();

    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(2)));
    visited[0][0][0] = true;

    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.emplace(make_pair(0, 0), make_pair(0, 0));

    while(!q.empty()){

        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second.first;
        int foo = q.front().second.second;
        q.pop();

        if(r == n - 1 and c == n - 1){
            return t;
        }

        for(int i = 0; i < 4; i++){

            int next_r = r + dr[i];
            int next_c = c + dc[i];
            int next_t = t + 1;
            int next_foo = foo;

            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n or arr[next_r][next_c] == -1 or visited[next_r][next_c][foo]){
                continue;
            }

            if(arr[next_r][next_c] != 1){
                if(arr[r][c] != 1){
                    continue;
                }
                if(arr[next_r][next_c] > 1){
                    if(next_t % arr[next_r][next_c] != 0){
                        next_r = r;
                        next_c = c;
                    }
                }else if(foo == 0){
                    if(next_t % m == 0){
                        next_foo++;
                    }else{
                        next_r = r;
                        next_c = c;
                    }    
                }else{
                    continue;
                }
            }

            visited[next_r][next_c][next_foo] = true;
            q.emplace(make_pair(next_r, next_c), make_pair(next_t, next_foo));

        }

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n));

    for(auto& row : arr){
        for(auto& x : row){
            cin >> x;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                int cnt = 0;
                if((i > 0 and arr[i - 1][j] != 1) or (i < n - 1) and arr[i + 1][j] != 1){
                    cnt++;
                }
                if((j > 0 and arr[i][j - 1] != 1) or (j < n - 1) and arr[i][j + 1] != 1){
                    cnt++;
                }
                if(cnt == 2){
                    arr[i][j] = -1;
                }
            }
        }
    }

    cout << bfs(arr, m);

    return 0;
}