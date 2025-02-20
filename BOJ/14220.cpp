#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> dp(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x){
                adj[i].emplace_back(j, x);
                dp[j][0] = min(dp[j][0], x);
            }
        }
    }

    for(int k = 1; k < n; k++){
        for(int i = 0; i < n; i++){
            for(auto& p : adj[i]){
                dp[p.first][k] = min(dp[p.first][k], dp[i][k - 1] + p.second);
            }
        }
    }

    int answer = 1e9;

    for(int i = 0; i < n; i++){
        answer = min(answer, dp[i][n - 2]);
    }

    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;
    
    return 0;

}