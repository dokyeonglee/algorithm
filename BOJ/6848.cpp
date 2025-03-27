#include <iostream>
#include <queue>

using namespace std;

int topology_sort(vector<vector<int>>& adj, vector<int>& in_degree){

    vector<int> dp(adj.size());
    dp[1] = 1;

    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int& next : adj[now]){
            dp[next] += dp[now];
            if(--in_degree[next] == 0){
                q.push(next);
            }
        }
    }

    return dp.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> in_degree(n + 1);

    while(1){
        int u, v;
        cin >> u >> v;
        if(u == 0){
            break;
        }
        adj[u].push_back(v);
        in_degree[v]++;
    }

    cout << topology_sort(adj, in_degree);

    return 0;

}