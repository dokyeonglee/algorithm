#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<vector<int>> dp(n + 1, vector<int>(2));

    for(int i = 1; i <= n; i++){
        if(str[i - 1] == 'A'){
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        }else{
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][1] = dp[i - 1][1];
        }
    }

    cout << dp[n][0];

    return 0;
}