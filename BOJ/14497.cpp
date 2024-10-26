#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& arr, int r, int c){

    int n = arr.size();
    int m = arr[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[r][c] = true;

    queue<pair<int, int>> q;
    q.emplace(r, c);

    int result = 0;

    while(1){

        result++;

        queue<pair<int, int>> temp;

        while(!q.empty()){

            auto now = q.front();
            q.pop();

            if(arr[now.first][now.second] == '#'){
                return result;
            }

            for(int i = 0; i < 4; i++){
                int next_r = now.first + dr[i];
                int next_c = now.second + dc[i];
                if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                    continue;
                }
                if(!visited[next_r][next_c]){
                    visited[next_r][next_c] = true;
                    if(arr[next_r][next_c] == '1'){
                        temp.emplace(next_r, next_c);
                        arr[next_r][next_c] = '0';
                    }else{
                        q.emplace(next_r, next_c);
                    }
                }
            }

        }

        q = temp;

    }

    return -1;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr(n);

    int r, c;
    cin >> r >> c;

    r--;
    c--;

    int _r, _c;
    cin >> _r >> _c;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << bfs(arr, r, c);

    return 0;
}