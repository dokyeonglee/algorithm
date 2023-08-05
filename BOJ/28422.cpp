#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<unsigned int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n + 1);

    dp[1] = -987654321;
    dp[2] = __builtin_popcount(arr[0] ^ arr[1]);

    for(int i = 3; i <= n; i++){
        int a = (arr[i - 1] ^ arr[i - 2]);
        dp[i] = max(dp[i], dp[i - 2] + __builtin_popcount(a));
        a ^= arr[i - 3];
        dp[i] = max(dp[i], dp[i - 3] + __builtin_popcount(a));
    }

    cout << max(0, dp[n]);

    return 0;
}