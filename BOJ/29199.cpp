#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    vector<long long> dp(n + 1);

    for(int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1], arr[i] - dp[i - 1]);
    }

    cout << dp[n];

    return 0;
}