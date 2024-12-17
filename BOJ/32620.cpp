#include <iostream>
#include <queue>

using namespace std;

long long bfs(vector<vector<int>>& adj, vector<int>& arr, vector<int>& brr, int src){

    vector<bool> visited(adj.size());
    visited[src] = true;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    long long result = 0;

    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        if(result < arr[now]){
            break;
        }
        result += brr[now];
        for(auto& next : adj[now]){
            if(!visited[next]){
                visited[next] = true;
                pq.emplace(-arr[next], next);
            }
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> brr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> brr[i];
    }

    vector<vector<int>> adj(n + 1);
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    cout << bfs(adj, arr, brr, r);

    return 0;
}