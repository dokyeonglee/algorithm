#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<long long> dp(5001);

    const int mod = 1e9 + 7;

    dp[0] = dp[1] = 1;

    for(int i = 2; i <= 5000; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i - 1 - j] % mod;
        }
        dp[i] %= mod;
    }

    while(t--){
        int e;
        cin >> e;
        cout << dp[e + 1] << "\n";
    }

    return 0;
}