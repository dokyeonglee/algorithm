#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
        a %= 7;
    }

    vector<vector<bool>> dp(2, vector<bool>(7));
    dp[1][0] = true;

    for(int& a : arr){
        for(int i = 0; i < 7; i++){
            if(dp[1][i]){
                dp[0][(i + a) % 7] = true;
                dp[0][i] = true;
            }
        }
        dp[1] = dp[0];
    }

    if(dp[0][4]){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;

}