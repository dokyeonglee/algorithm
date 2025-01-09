#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    int p;
    cin >> p;

    vector<vector<bool>> check(n + 1, vector<bool>(n + 1));

    while(p--){
        int r, c;
        cin >> r >> c;
        check[r][c] = true;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<int>> dp2(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
            if(dp[i - 1][j] + arr[i][j] == dp[i][j]){
                dp2[i][j] = dp2[i - 1][j] + check[i][j];
            }
            if(dp[i][j - 1] + arr[i][j] == dp[i][j]){
                dp2[i][j] = max(dp2[i][j], dp2[i][j - 1] + check[i][j]);
            }
        }
    }

    cout << dp[n][n] << " " << dp2[n][n];

    return 0;

}