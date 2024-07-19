#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(n, 987654321));
    vector<pair<int, int>> edges;

    for(int i = 0; i < n; i++){
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        arr[u][v] = c;
        arr[v][u] = c;
        edges.emplace_back(u, v);
    }

    vector<vector<int>> dp(arr);

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for(auto& e : edges){
        auto dp2 = arr;
        dp2[e.first][e.second] = 987654321;
        dp2[e.second][e.first] = 987654321;
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dp2[i][j] = min(dp2[i][j], dp2[i][k] + dp2[k][j]);
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(dp[i][j] < dp2[i][j]){
                    result++;
                }
            }
        }
        cout << result << " ";
    }

    return 0;
}