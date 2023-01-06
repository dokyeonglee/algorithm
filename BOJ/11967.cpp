#include <iostream>
#include <queue>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<vector<bool>>& light, vector<vector<int>>& switches, int n){

    vector<vector<bool>> visited(n, vector<bool>(n));
    visited[0][0] = true;

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    light[0][0] = true;

    int result = 0;
    bool check = false;

    while(!q.empty()){

        auto now = q.front();
        q.pop();

        for(auto sw : switches[now.first * n + now.second]){
            if(!light[sw / n][sw % n]){
                light[sw / n][sw % n] = true;
                result++;
                check = true;
            }
        }

        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
                continue;
            }
            if(!visited[next_r][next_c] and light[next_r][next_c]){
                visited[next_r][next_c] = true;
                q.push(make_pair(next_r, next_c));
            }
        }
    }

    if(check){
        result += bfs(light, switches, n);
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> switches(n * n);

    for(int i = 0; i < m; i++){
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        a--;
        b--;
        switches[u * n + v].push_back(a * n + b);
    }

    vector<vector<bool>> light(n, vector<bool>(n));

    cout << bfs(light, switches, n) + 1;

    return 0;
}