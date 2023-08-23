#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& tree, vector<vector<int>>& _tree, vector<bool>& visited, int now){
    visited[now] = true;
    for(int next : _tree[now]){
        if(!visited[next]){
            tree[now].push_back(next);
            dfs(tree, _tree, visited, next);
        }
    }
}

int solve(vector<vector<int>>& tree, vector<int>& dp, int now, int state){

    int& ret = dp[now];
    if(ret != -1){
        return ret;
    }

    if(state == 0){
        ret = 0;
        for(int next : tree[now]){
            ret = max(ret, solve(tree, dp, next, 1));
        }
    }else{
        ret = 1987654321;
        for(int next : tree[now]){
            ret = min(ret, solve(tree, dp, next, 0));
        }
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r;
    cin >> n >> r;

    vector<vector<int>> _tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        _tree[u].push_back(v);
        _tree[v].push_back(u);
    }

    int l;
    cin >> l;

    vector<int> leaf(l);
    vector<int> dp(n + 1, -1);

    for(int i = 0; i < l; i++){
        cin >> leaf[i];
        cin >> dp[leaf[i]];
    }

    vector<bool> visited(n + 1);
    vector<vector<int>> tree(n + 1);
    dfs(tree, _tree, visited, r);

    solve(tree, dp, r, 0);

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;
        cout << dp[x] << "\n";
    }

    return 0;
}