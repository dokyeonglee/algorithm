#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(7));
    dp[0][0] = 1;

    const int mod = 998244353;

    long long answer = 1;

    for(int i = 1; i <= n; i++){
        dp[i][0] = 6 * dp[i - 1][0] % mod;
        answer = 7 * answer % mod;
        for(int j = 1; j <= 6; j++){
            dp[i][j] = (dp[i - 1][j - 1] + 6 * dp[i - 1][j]) % mod;
        }
    }

    for(int i = 0; i <= 6; i++){
        answer = (answer - dp[n][i] + mod) % mod;
    }

    cout << answer;

    return 0;
}