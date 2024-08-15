#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> m >> n;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(4)));

    for(int i = 1; i <= n; i++){
        dp[i][1][0] = 1;
    }

    for(int i = 1; i <= m; i++){
        dp[1][i][3] = 1;
    }

    const int mod = 1e5;
//(전전) (전)
//0 : 위 위
//1 : 위 오
//2 : 오 위
//3 : 오 오
    for(int i = 2; i <= n; i++){
        for(int j = 2; j <= m; j++){
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][2]) % mod;
            dp[i][j][1] = dp[i][j - 1][0];
            dp[i][j][2] = dp[i - 1][j][3];
            dp[i][j][3] = (dp[i][j - 1][1] + dp[i][j - 1][3]) % mod;
        }
    }

    int answer = 0;

    for(int i = 0; i < 4; i++){
        answer += dp[n][m][i];
    }

    cout << answer % mod;

    return 0;
}