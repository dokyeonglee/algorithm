#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n, w;
        cin >> n >> w;

        vector<vector<int>> dp(n + 1, vector<int>(w + 1));

        for(int i = 1; i <= n; i++){

            int value, cost;
            cin >> value >> cost;

            for(int j = 0; j <= w; j++){
                if(j < cost) {
                    dp[i][j] = dp[i  - 1][j];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost] + value);
                }
            }

        }

        cout << dp[n][w] << "\n";
        
    }

    return 0;
}