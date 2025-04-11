#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<vector<long long>> dp(2, vector<long long>(n + 1));

    const int mod = 1e9 + 7;

    for(int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }

    int x = 0;

    for(int i = 2; i <= l; i++){
        for(int j = 1; j <= n; j++){
            for(int k = j; k <= n; k += j){
                dp[x][k] += dp[x ^ 1][j];
            }
            dp[x][j] %= mod;
            dp[x ^ 1][j] = 0;
        }
        x ^= 1;
    }

    long long answer = 0;

    for(int i = 1; i <= n; i++){
        answer = (answer + dp[l & 1][i]) % mod;
    }

    cout << answer;

    return 0;

}