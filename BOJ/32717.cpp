#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m + 2, -1e9));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    int answer = -1e9;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(0, max(dp[i - 1][j], dp[i][j - 1])) + arr[i][j];
            answer = max(answer, dp[i][j]);
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 1; j--){
            dp[i][j] = max(0, max(dp[i - 1][j], dp[i][j + 1])) + arr[i][j];
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

    return 0;
}