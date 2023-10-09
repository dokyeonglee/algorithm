#include <iostream>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>& graph){

    vector<int> visited(graph.size(), -1);
    visited[1] = 0;

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int next : graph[now]){
            if(visited[next] == -1){
                visited[next] = visited[now] + 1;
                q.push(next);
            }
        }
    }

    return visited;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> distance = bfs(graph);
    vector<int> cnt(n + 1);

    for(int i = 1; i <= n; i++){
        if(distance[i] != -1){
            cnt[distance[i]]++;
        }
    }

    const int mod = 1e9 + 7;

    long long answer = 1;

    for(int i = 0; i <= n; i++){
        answer *= (cnt[i] + 1);
        answer %= mod; 
    }

    cout << (answer - 1) % mod;

    return 0;
}