#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> dp(2, vector<int>(m, -1));
        dp[1][0] = 0;

        for(int i = 0; i < n; i++){

            int x;
            cin >> x;

            for(int j = m - 1; j >= 0; j--){
                if(dp[i & 1 ^ 1][j] != -1){
                    dp[i & 1][j] = max(dp[i & 1][j], dp[i & 1 ^ 1][j]);
                    dp[i & 1][(j + x) % m] = max(dp[i & 1][(j + x) % m], dp[i & 1 ^ 1][j] + 1);
                }
            }

        }

        cout << dp[n & 1 ^ 1][0] << "\n";

    }

    return 0;

}