#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>>& tree, vector<int>& sz, int now){
    if(tree[now].size() == 0){
        return 1;
    }
    for(int& next : tree[now]){
        sz[now] += dfs(tree, sz, next);
    }
    return sz[now];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        tree[p].push_back(i);
    }

    vector<int> sz(n + 1, 1);

    dfs(tree, sz, tree[0][0]);

    long long odd = 0;
    long long even = 0;

    long long cnt = 0;

    for(int i = 1; i <= n; i++){
        long long lca_cnt = (long long)sz[i] * sz[i];
        for(int j : tree[i]){
            lca_cnt -= (long long)sz[j] * sz[j];
        }
        odd += lca_cnt / 2 * i;
        even += lca_cnt / 2 * i;
        if(cnt % 2){
            even += i;
        }else{
            odd += i;
        }
        cnt += lca_cnt;
    }

    cout << even << " " << odd;

    return 0;
}