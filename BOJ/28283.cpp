#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& adj, vector<int>& visited){

    queue<int> q;

    for(int i = 1; i < visited.size(); i++){
        if(visited[i] == 0){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : adj[now]){
            if(visited[next] == -1){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<long long> earn(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> earn[i];
    }

    vector<vector<int>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1, -1);

    for(int i = 0; i < y; i++){
        int a;
        cin >> a;
        visited[a] = 0;
    }

    bfs(adj, visited);

    for(int i = 1; i <= n; i++){
        if(earn[i] and visited[i] == -1){
            cout << -1;
            return 0;
        }
        earn[i] *= visited[i];
    }

    sort(earn.begin() + 1, earn.end(), greater<>());

    long long answer = 0;

    for(int i = 1; i <= x; i++){
        answer += earn[i];
    }

    cout << answer;

    return 0;
}