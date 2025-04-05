#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> dp(n + 2, vector<int>(m + 1, -1e9));
    vector<vector<int>> dp2(n + 2, vector<int>(m + 2, -1e9));

    dp[n][0] = 0;
    dp2[n][m + 1] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]) + arr[i][j];
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = m; j >= 1; j--){
            dp2[i][j] = max(dp2[i][j + 1], dp2[i + 1][j]) + arr[i][j];
        }
    }

    int answer = -1e9;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            answer = max(answer, dp[i][j] + dp2[i][j]);
        }
    }

    cout << answer;

    return 0;

}