#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<long long> dp(3);
    const int mod = 1e9 + 7;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'a'){
            dp[0] = (2 * dp[0] + 1) % mod;
        }else if(str[i] == 'b'){
            dp[1] = (dp[0] + 2 * dp[1]) % mod;
        }else{
            dp[2] = (dp[1] + 2 * dp[2]) % mod;
        }
    }

    cout << dp.back();

    return 0;
}