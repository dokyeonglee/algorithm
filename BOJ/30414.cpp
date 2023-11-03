#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& dp, vector<int>& arr, vector<int>& target, int now, int p){

    int& ret = dp[now];

    if(ret != -1e9){
        return ret;
    }

    ret = 0;

    bool check = false;

    for(int next : tree[now]){
        if(next != p){
            ret += dfs(tree, dp, arr, target, next, now);
            check = true;
        }
    }

    if(check){
        ret += target[now] - arr[now];
    }else{
        ret += max(0, target[now] - arr[now]);
    }

    ret = max(0, ret);

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    vector<int> arr(n + 1);
    vector<int> target(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> target[i];
    }

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> dp(n + 1, -1e9);

    cout << dfs(tree, dp, arr, target, p, -1);

    return 0;
}