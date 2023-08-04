#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_tree(vector<vector<int>>& tree, vector<vector<int>>& _tree, int now, int prev){
    for(int next : _tree[now]){
        if(next != prev){
            tree[now].push_back(next);
            make_tree(tree, _tree, next, now);
        }
    }
}

int dfs(vector<vector<int>>& tree, vector<int>& arr, vector<vector<int>>& dp, vector<bool>& check, int now, int x){

    int& ret = dp[now][x];
    if(ret != -1){
        return ret;
    }
    
    ret = arr[now] * x;

    if(x){
        for(int next : tree[now]){
            int a = dfs(tree, arr, dp, check, next, 0);
            ret += a;
        }
    }else{
        for(int next : tree[now]){
            int a = dfs(tree, arr, dp, check, next, 0);
            int b = dfs(tree, arr, dp, check, next, 1);
            if(a < b){
                ret += b;
                check[next] = true;
            }else{
                ret += a;
            }
        }
    }

    return ret;
}

void dfs(vector<int>& answer, vector<vector<int>>& tree, vector<bool>& check, int now, int x){
    if(x){
        answer.push_back(now);
    }
    for(int next : tree[now]){
        dfs(answer, tree, check, next, ~x & check[next]);
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> _tree(n + 1);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        _tree[u].push_back(v);
        _tree[v].push_back(u);
    }

    vector<vector<int>> tree(n + 1);
    make_tree(tree, _tree, 1, 1);

    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    vector<bool> check(n + 1);

    dfs(tree, arr, dp, check, 1, 0);
    dfs(tree, arr, dp, check, 1, 1);

    check[1] = (dp[1][0] < dp[1][1]);

    vector<int> answer;

    dfs(answer, tree, check, 1, check[1]);

    sort(answer.begin(), answer.end());

    cout << max(dp[1][0], dp[1][1]) << "\n";

    for(int x : answer){
        cout << x << " ";
    }

    return 0;
}