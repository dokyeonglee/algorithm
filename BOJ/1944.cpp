#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
}

void bfs(vector<string>& maze, vector<pair<int, pair<int, int>>>& edges, int src){

    int n = maze.size();
    
    vector<int> visited(n * n, 987654321);
    visited[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int next_r = now / n + dr[i];
            int next_c = now % n + dc[i];
            if(next_r < 0 or next_r >= n or next_c < 0 or next_c >= n){
                continue;
            }
            if(visited[next_r * n + next_c] == 987654321 and maze[next_r][next_c] != '1'){
                if(maze[next_r][next_c] == 'S' or maze[next_r][next_c] == 'K'){
                    edges.push_back(make_pair(visited[now] + 1, make_pair(src, next_r * n + next_c)));
                }
                visited[next_r * n + next_c] = visited[now] + 1;
                q.push(next_r * n + next_c);
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> maze(n);
    for(int i = 0; i < n; i++){
        cin >> maze[i];
    }

    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == 'S' or maze[i][j] == 'K'){
                bfs(maze, edges, i * n + j);
            }
        }
    }

    vector<int> parent(n * n + 1);
    for(int i = 1; i <= n * n; i++){
        parent[i] = i;
    }

    sort(edges.begin(), edges.end());

    int answer = 0;
    int cnt = 1;

    for(auto edge : edges){
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find_parent(parent, u) != find_parent(parent, v)){
            answer += c;
            cnt++;
            union_parent(parent, u, v);
        }
    }

    if(cnt != m + 1){
        answer = -1;
    }

    cout << answer;

    return 0;
}