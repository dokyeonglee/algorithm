#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> dp(101);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i <= 100; i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 1; j <= i - 2; j++){
            dp[i] = max(dp[i], (j + 1) * dp[i - j - 2]);
        }
    }

    cout << dp[n];

    return 0;
}