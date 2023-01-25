#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr, vector<vector<bool>>& visited, int r, int c, int height){

    vector<vector<bool>> temp_visited(arr.size(), vector<bool>(arr[0].size()));
    temp_visited[r][c] = true;
    visited[r][c] = true;

    auto temp(arr);

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    int result = 0;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        result += height - (temp[now.first][now.second] - '0');
        temp[now.first][now.second] = '0' + height;

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                return 0;
            }
            if(!temp_visited[next_r][next_c] and temp[next_r][next_c] - '0' < height){
                temp_visited[next_r][next_c] = true;
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    arr = temp;

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);

    int min_height = 10;
    int max_height = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        for(int j = 0; j < m; j++){
            min_height = min(min_height, arr[i][j] - '0');
            max_height = max(max_height, arr[i][j] - '0');
        }
    }

    int answer = 0;

    for(int height = min_height + 1; height <= max_height; height++){
        vector<vector<bool>> visited(n, vector<bool>(m));
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(!visited[i][j] and arr[i][j] - '0' < height){
                    answer += bfs(arr, visited, i, j, height);
                }
            }
        }
    }

    cout << answer;

    return 0;
}