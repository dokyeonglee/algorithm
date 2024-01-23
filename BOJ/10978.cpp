#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<long long> dp(21);

    dp[0] = 1;

    for(int i = 2; i <= 20; i++){
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
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