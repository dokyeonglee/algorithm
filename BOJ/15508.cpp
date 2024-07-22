#include <iostream>
#include <vector>

using namespace std;

int find_parent(vector<int>& parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find_parent(parent, parent[x]);
}

void union_parent(vector<int>& parent, vector<int>& sz, int x, int y){
    x = find_parent(parent, x);
    y = find_parent(parent, y);
    if(x != y){
        sz[x] += sz[y];
        parent[y] = x;
    }
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    if(k > n){
        cout << "DOOMED";
        return 0;
    }

    vector<int> parent(n + 1);
    vector<int> sz(n + 1, 1);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    while(m--){
        int u, v;
        cin >> u >> v;
        union_parent(parent, sz, u, v);
    }

    vector<int> arr(1, 0);
    
    for(int i = 1; i <= n; i++){
        if(find_parent(parent, i) == i){
            arr.push_back(sz[i]);
        }
    }

    vector<vector<bool>> dp(arr.size(), vector<bool>(k + 1));
    dp[0][0] = true;

    for(int i = 1; i < arr.size(); i++){
        for(int j = 0; j < arr[i]; j++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = arr[i]; j <= k; j++){
            dp[i][j] = (dp[i - 1][j] | dp[i - 1][j - arr[i]]);
        }
    }

    if(dp[arr.size() - 1][k]){
        cout << "SAFE";
    }else{
        cout << "DOOMED";
    }

    return 0;
}