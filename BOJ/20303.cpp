#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, vector<int>& candy, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    parent[y] = x;
    sz[x] += sz[y];
    candy[x] += candy[y];
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> parent(n + 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    vector<int> sz(n + 1, 1);
    vector<int> candy(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> candy[i];
    }

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find_parent(parent, u) != find_parent(parent, v)){
            union_parent(parent, sz, candy, u, v);
        }
    }

    vector<int> w;
    vector<int> v;

    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            w.push_back(sz[i]);
            v.push_back(candy[i]);
        }
    }

    vector<vector<int>> dp(w.size() + 1, vector<int>(k));

    for(int i = 1; i <= w.size(); i++){
        for(int j = 1; j < k; j++){
            if(w[i - 1] <= j){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[w.size()][k - 1];

    return 0;
}