#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n, k, w;
        cin >> n >> k >> w;
        vector<int> arr(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        vector<vector<int>> dp(2, vector<int>(n + 2));
        int answer = 0;
        for(int i = 1; i <= k; i++){
            for(int j = n - w + 1; j >= 1; j--){
                dp[i & 1][j] = max(dp[i & 1][j + 1], dp[i & 1 ^ 1][j + w] + arr[j + w - 1] - arr[j - 1]);
            }
        }
        cout << dp[k & 1][1] << "\n";
    }

    return 0;

}