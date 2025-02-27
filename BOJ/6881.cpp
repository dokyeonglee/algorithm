#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool bfs(vector<vector<int>>& arr, int step){
    vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size()));
    queue<pair<int, int>> q;
    for(int i = 0; i < arr[0].size(); i++){
        if((1 << arr[0][i]) & step){
            visited[0][i] = true;
            q.emplace(0, i);
        }
    }
    while(!q.empty()){
        auto now = q.front();
        q.pop();
        if(now.first == arr.size() - 1){
            return true;
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= arr.size() or next_c < 0 or next_c >= arr[0].size()){
                continue;
            }
            if(!visited[next_r][next_c] and (step & (1 << arr[next_r][next_c]))){
                visited[next_r][next_c] = true;
                q.emplace(next_r, next_c);
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }

    int candidate = 0;

    for(int i = 0; i < m; i++){
        candidate |= (1 << arr[0][i]);
    }

    for(int i = 0; i < 10; i++){
        for(int j = i; j < 10; j++){
            for(int k = j; k < 10; k++){
                int step = (1 << i) | (1 << j) | (1 << k);
                if(!(candidate & step)){
                    continue;
                }
                if(bfs(arr, step)){
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }
        }
    }

    cout << "-1 -1 -1";

    return 0;

}