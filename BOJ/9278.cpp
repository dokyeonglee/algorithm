#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e6;

    vector<vector<int>> dp(1005, vector<int>(1005));

    string str;

    while(cin >> str){

        int n = str.size();

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = 0;
            }
        }

        if(str[0] != ')'){
            dp[1][1] = 1;
        }else{
            cout << "0\n";
            continue;
        }

        for(int i = 2; i <= n; i++){
            if(str[i - 1] != '('){
                dp[i][0] = dp[i - 1][1];
            }
            for(int j = 1; j <= i; j++){
                if(str[i - 1] == '('){
                    dp[i][j] = dp[i - 1][j - 1];
                }else if(str[i - 1] == ')'){
                    dp[i][j] = dp[i - 1][j + 1];
                }else{
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
                }
                
            }
        }

        cout << dp[n][0] << "\n";
        
    }

    return 0;
}