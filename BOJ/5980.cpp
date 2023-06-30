#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int bfs(vector<string>& maze, map<pair<int, int>, pair<int, int>>& teleport, pair<int, int>& src){

    int n = maze.size();
    int m = maze[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m));
    visited[src.first][src.second] = true;

    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, src));

    while(!q.empty()){
        int cnt = q.front().first;
        auto now = q.front().second;
        q.pop();
        if(maze[now.first][now.second] == '='){
            return cnt;
        }
        for(int i = 0; i < 4; i++){
            int next_r = now.first + dr[i];
            int next_c = now.second + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= m){
                continue;
            }
            auto next = make_pair(next_r, next_c);
            if(teleport.count(next)){
                next = teleport[next];
            }
            if(!visited[next.first][next.second] and maze[next.first][next.second] != '#'){
                visited[next.first][next.second] = true;
                q.push(make_pair(cnt + 1, next));
            }
        }
    }

    return -1;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    vector<vector<pair<int, int>>> _teleport(26);
    pair<int, int> src;

    for(int i = 0; i < n; i++){
        cin >> maze[i];
        for(int j = 0; j < m; j++){
            if(maze[i][j] >= 'A' and maze[i][j] <= 'Z'){
                _teleport[maze[i][j] - 'A'].push_back(make_pair(i, j));
            }else if(maze[i][j] == '@'){
                src = make_pair(i, j);
            }
        }
    }

    map<pair<int, int>, pair<int, int>> teleport;

    for(int i = 0; i < 26; i++){
        if(_teleport[i].size() == 2){
            teleport[_teleport[i][0]] = _teleport[i][1];
            teleport[_teleport[i][1]] = _teleport[i][0];
        }
    }

    cout << bfs(maze, teleport, src);

    return 0;
}