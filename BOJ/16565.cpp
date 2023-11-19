#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e4 + 7;

    vector<vector<int>> dp(53, vector<int>(53));
    dp[0][0] = 1;

    for(int i = 1; i <= 52; i++){
        dp[i][0] = 1;
        for(int j = 1; j <= i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }

    int n;
    cin >> n;

    long long answer = 0;

    int sign = 1;

    for(int i = 1; 4 * i <= n; i++){
        answer = (answer + sign * dp[13][i] * dp[52 - 4 * i][n - 4 * i] % mod + mod) % mod;
        sign *= -1;
    }

    cout << answer;    


    return 0;
}