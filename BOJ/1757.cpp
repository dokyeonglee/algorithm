#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    
    for(int i = 1; i <= n; i++){

        dp[i][0] = dp[i - 1][0];

        for(int j = 1; j <= m and i > j; j++){
            dp[i][0] = max(dp[i][0], dp[i - j][j]);
        }

        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i - 1][j - 1] + arr[i];
        }

    }

    cout << dp[n][0];

    return 0;
}