#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n + 1);

    dp[0] = 1;
    dp[1] = 1;

    int max_height = arr[1];
    int max_height_idx = 1;

    const int mod = 1e9 + 7;

    for(int i = 2; i <= n; i++){
        if(max_height < arr[i]){
            dp[i] = 1ll * (i - max_height_idx + 1) * dp[i - 1] % mod;
            max_height = arr[i];
            max_height_idx = i;
        }else{
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[n];

    return 0;
}