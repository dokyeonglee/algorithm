#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int dfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, vector<vector<vector<int>>>& possilbe_tile_and_next_dir, int k, int current_r, int current_c, int current_dir, int x){

    int n = arr.size() - 1;

    if(k < 0){
        return 1e9;
    }

    if(current_r == n and current_c == n){
        if(current_dir == 1 and arr[current_r][current_c] != 5 or current_dir == 2 and arr[current_r][current_c] != 2){
            k--;
        }
        if(k < 0 or k and x == n * n){
            return 1e9;
        }
        return x;
    }

    int result = 1e9;

    for(auto& v : possilbe_tile_and_next_dir[current_dir]){

        int next_dir = v[1];
        int next_r = current_r + dr[next_dir];
        int next_c = current_c + dc[next_dir];

        if(next_r < 1 or next_r > n or next_c < 1 or next_c > n or visited[next_r][next_c]){
            continue;
        }

        visited[next_r][next_c] = true;

        if(arr[current_r][current_c] != v[0]){
            result = min(result, dfs(arr, visited, possilbe_tile_and_next_dir, k - 1, next_r, next_c, next_dir, x + 1));
        }else{
            result = min(result, dfs(arr, visited, possilbe_tile_and_next_dir, k, next_r, next_c, next_dir, x + 1));
        }

        visited[next_r][next_c] = false;

    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;  

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    int minimum_replace = (arr[1][1] != 1 and arr[1][1] != 5) + (arr[n][n] != 2 and arr[n][n] != 5);

    if(k < minimum_replace){
        cout << -1;
        return 0;
    }

    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1));

    vector<vector<vector<int>>> possilbe_tile_and_next_dir{//possilbe_tile_and_next_dir[idx] := idx방향으로 진입한다고 했을 때, 진입가능한 타일과 진입했을 때 바뀌는 방향
                            {{0, 1}, {1, 3}, {4, 0}},
                            {{1, 2}, {3, 0}, {5, 1}},
                            {{2, 1}, {3, 3}, {4, 2}}, 
                            {{0, 2}, {2, 0}, {5, 3}}
                        };
  
    int answer = dfs(arr, visited, possilbe_tile_and_next_dir, k, 1, 1, 1, 1);

    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;

    return 0;

}