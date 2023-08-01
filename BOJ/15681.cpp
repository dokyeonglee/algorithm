#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& dp, vector<bool>& visited, int now){
    visited[now] = true;
    dp[now] = 1;
    for(int next : tree[now]){
        if(!visited[next]){
            dp[now] += dfs(tree, dp, visited, next);
        }
    }
    return dp[now];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    vector<vector<int>> tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> dp(n + 1, -1);
    vector<bool> visited(n + 1);

    dfs(tree, dp, visited, r);

    for(int i = 0; i < q; i++){
        int u;
        cin >> u;
        cout << dp[u] << "\n";
    }

    return 0;
}