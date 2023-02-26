#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        in_degree[u]++;
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0){
            q.push(i);
        }
    }

    int answer = 0;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        answer++;
        for(int next : adj[now]){
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    cout << answer;

    return 0;
}