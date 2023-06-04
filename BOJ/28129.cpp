#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    vector<int> brr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i] >> brr[i];
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(3001));
    for(int i = arr[1]; i <= brr[1]; i++){
        dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = arr[i - 1]; j <= brr[i - 1]; j++){
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for(int j = arr[i]; j <= brr[i]; j++){
            dp[i][j] = dp[i - 1][min(brr[i - 1], j + k)] - dp[i - 1][max(arr[i - 1], j - k) - 1];
            dp[i][j] %= 1000000007;
        }
    }

    long long answer = 0;
    for(int i = arr[n]; i <= brr[n]; i++){
        answer += dp[n][i];
        answer %= 1000000007;
    }

    cout << answer;

    return 0;
}