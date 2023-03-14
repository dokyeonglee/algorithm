#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<int>>& arr, int d, int k){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    queue<pair<int, int>> q;
    
    for(int i = 0; i < m; i++){
        if(arr[0][i] <= d){
            visited[0][i] = true;
            q.push(make_pair(0, i));
        }
    }

    for(int i = 1; i < n; i++){
        if(!visited[i][0] and arr[i][0] <= d){
            visited[i][0] = true;
            q.push(make_pair(i, 0));
        }
        if(!visited[i][m - 1] and arr[i][m - 1] <= d){
            visited[i][m - 1] = true;
            q.push(make_pair(i, m - 1));
        }
    }

    while(!q.empty()){
        auto now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            if(!visited[next_r][next_c] and arr[next_r][next_c] <= d){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt += visited[i][j];
        }
    }

    return cnt;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int left = 1;
    int right = 1e6;

    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        if(bfs(arr, mid, k) >= k){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}