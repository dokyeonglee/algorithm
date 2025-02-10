#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dp(2001);
    dp[0] = 1;

    const int mod = 100999;

    for(int i = 1; i <= 2000; i++){
        for(int j = 2000; j >= i; j--){
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }

    return 0;

}