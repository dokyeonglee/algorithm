#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n;
    cin >> n;

    vector<int> dp(5);

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        dp[4] = (dp[3] + dp[4] * 26ll) % mod;
        for(int j = 3; j >= 1; j--){
            dp[j] = (dp[j - 1] + dp[j] * 25ll) % mod;
        }
        dp[0] = dp[0] * 25ll % mod;
    }

    cout << dp[4];

    return 0;
}