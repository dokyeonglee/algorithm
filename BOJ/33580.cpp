#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> cat(t + 1);

    for(int i = 1; i <= t; i++){
        cin >> cat[i];
    }

    vector<vector<int>> dp(2, vector<int>(n + 1));

    for(int i = 1; i <= t; i++){
        for(int u = 1; u <= n; u++){
            dp[1][u] = dp[0][u];
            for(auto& v : tree[u]){
                dp[1][u] = max(dp[1][u], dp[0][v]);
            }
        }
        dp[1][cat[i]]++;
        dp[0] = dp[1];
    }

    cout << *max_element(dp[1].begin(), dp[1].end());

    return 0;

}