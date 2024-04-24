#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n + 1);
    vector<int> y(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }

    for(int i = 1; i <= n; i++){
        cin >> y[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, (1 << 31) - 1));

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + (x[i] - y[j]) * (x[i] - y[j]);
        }
    }

    cout << dp[n][n];

    return 0;
}