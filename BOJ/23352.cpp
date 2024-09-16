#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

pair<int, int> bfs(vector<vector<int>>& arr, int r, int c){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> distance(n, vector<int>(m, -1));
    distance[r][c] = 0;

    queue<pair<int, int>> q;
    q.emplace(r, c);

    int max_distance = 0;
    int end_point_value = arr[r][c];

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(max_distance < distance[now.first][now.second]){
            max_distance = distance[now.first][now.second];
            end_point_value = arr[now.first][now.second];
        }else if(max_distance == distance[now.first][now.second]){
            end_point_value = max(end_point_value, arr[now.first][now.second]);
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            if(distance[next_r][next_c] == -1 and arr[next_r][next_c] != 0){
                distance[next_r][next_c] = distance[now.first][now.second] + 1;
                q.emplace(next_r, next_c);
            }
        }
    }

    return make_pair(max_distance, arr[r][c] + end_point_value);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    pair<int, int> answer;

    for(int i = 0; i < n; i++){
        for(int j = 0;j < m; j++){
            if(arr[i][j]){
                answer = max(answer, bfs(arr, i, j));
            }
        }
    }

    cout << answer.second;

    return 0;
}