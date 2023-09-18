#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(m + 1, vector<int>(k));
    
    for(int i = 1; i <= n; i++){
        if(arr[i]){
            dp[1][arr[i] % k]++;
        }
    }
    
    for(int i = 1; i < m; i++){
        for(int j = 0; j < k; j++){
            for(int x = 1; x <= n; x++){
                dp[i + 1][(j * 10 + arr[x]) % k] += dp[i][j];
                dp[i + 1][(j * 10 + arr[x]) % k] %= mod;
            }    
        }
    }

    cout << dp[m][0];

    return 0;
}