#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int mod = 1e9 + 7;

    int n;
    cin >> n;

    string str;
    cin >> str;

    long long t = 1;

    long long answer = 0;

    vector<int> dp(n + 1);
    vector<int> dp2(n + 1);
    vector<int> dp3(n + 1);

    for(int i = n - 1; i >= 0; i--){
        dp[i] = dp[i + 1] + (str[i] == 'K');
    }

    for(int i = n - 1; i >= 0; i--){
        if(str[i] == 'C'){
            dp2[i] = dp2[i + 1] + dp[i + 1];
        }else{
            dp2[i] = dp2[i + 1];
        }
        dp2[i] %= mod;
    }

    for(int i = n - 1; i >= 0; i--){
        if(str[i] == 'O'){
            dp3[i] = dp3[i + 1] + dp2[i + 1];
        }else{
            dp3[i] = dp3[i + 1];
        }
        dp3[i] %= mod;
    }

    for(int i = 0; i < str.size(); i++){
        if(str[i] == 'R'){
            answer = (answer + t * dp3[i] % mod) % mod;
        }
        t = 2 * t % mod;
    }

    cout << answer;

    return 0;
}