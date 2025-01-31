#include <iostream>
#include <vector>

using namespace std;

double solve(vector<int>& arr, vector<double>& dp, int x){
    if(x == 0){
        return 0;
    }
    auto& ret = dp[x];
    if(ret != -1){
        return ret;
    }
    ret = 1;
    for(int i = 1; i <= arr[x]; i++){
        ret += solve(arr, dp, x - i) / arr[x];
    }
    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<double> dp(n + 1, -1);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        if(arr[i] < i){
            dp[i] = (dp[i - 1] - dp[i - arr[i] - 1]) / arr[i] + 1;
        }else{
            dp[i] = dp[i - 1] / arr[i] + 1;
        }
        dp[i] += dp[i - 1];
    }

    cout << fixed;
    cout.precision(10);
    cout << dp[n] - dp[n - 1];
    
    return 0;

}