#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<long long> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<long long> dp(n + 1);

    int left = 0;
    int right = 1;

    long long sum = 0;

    while(right <= n){
        sum += arr[right];
        dp[right] = dp[right - 1];
        while(sum >= k){
            dp[right] = max(dp[right], dp[left] + sum - k);
            sum -= arr[++left];
        }
        right++;
    }

    cout << dp[n];

    return 0;
}