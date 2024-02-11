#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>>& adj, vector<int>& dp, int now){

    if(adj[now].size() == 0){
        return 1;
    }

    int& ret = dp[now];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    for(int& next : adj[now]){
        ret = max(ret, solve(adj, dp, next) + 1);
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> adj(n + 1);
    
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(arr[u] < arr[v]){
            adj[u].push_back(v);
        }else if(arr[u] > arr[v]){
            adj[v].push_back(u);
        }
    }

    vector<int> dp(n + 1, -1);

    for(int i = 1; i <= n; i++){
        cout << solve(adj, dp, i) << "\n";
    }

    return 0;
}