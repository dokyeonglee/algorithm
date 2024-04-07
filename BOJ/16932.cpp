#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, vector<vector<int>>& visited, int r, int c, int shape_number){

    visited[r][c] = shape_number;

    queue<pair<int, int>> q;
    q.emplace(r, c);

    int result = 0;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        result++;

        for(int i = 0; i < 4; i++){

            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];

            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                continue;
            }

            if(visited[next_r][next_c] == -1 and arr[next_r][next_c] == 1){
                visited[next_r][next_c] = shape_number;
                q.emplace(next_r, next_c);
            }

        }
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i =  0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<int> shape_size;

    int shape_number = 0;

    for(int i =  0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == -1 and arr[i][j] == 1){
                shape_size.push_back(bfs(arr, visited, i, j, shape_number++));
            }
        }
    }

    int answer = 0;

    vector<bool> check(shape_size.size());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(arr[i][j] == 0){

                int result = 1;

                for(int k = 0; k < 4; k++){

                    int next_r = i + dr[k];
                    int next_c = j + dc[k];

                    if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                        continue;
                    }

                    shape_number = visited[next_r][next_c];

                    if(arr[next_r][next_c] == 1 and !check[shape_number]){
                        check[shape_number] = true;
                        result += shape_size[shape_number];
                    }

                }

                for(int k = 0; k < 4; k++){

                    int next_r = i + dr[k];
                    int next_c = j + dc[k];

                    if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                        continue;
                    }

                    shape_number = visited[next_r][next_c];

                    if(arr[next_r][next_c] == 1){
                        check[shape_number] = false;
                    }

                }

                answer = max(answer, result);

            }
        }
    }

    cout << answer;

    return 0;
}