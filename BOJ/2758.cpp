#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<vector<long long>> dp(11, vector<long long>(2001));
    fill(dp[0].begin(), dp[0].end(), 1);

    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 2000; j++){
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j / 2];
        }
    }

    while(t--){
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }

    return 0;
}