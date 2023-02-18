#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 5, vector<int>(m + 5));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n + 5, vector<int>(m + 5));

    for(int i = 1; i <= m; i++){
        dp[1][i] = dp[1][i - 1] + arr[1][i];
    }

    for(int i = 2; i <= n; i++){
        vector<int> left(m + 5, -987654321);
        for(int j = 1; j <= m; j++){
            left[j] = max(dp[i - 1][j], left[j - 1]) + arr[i][j];
        }
        vector<int> right(m + 5, -987654321);
        for(int j = m; j >= 1; j--){
            right[j] = max(dp[i - 1][j], right[j + 1]) + arr[i][j];
        }
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(left[j], right[j]);
        }
    }

    cout << dp[n][m];

    return 0;
}