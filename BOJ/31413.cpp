#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(2 * n);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int a, d;
    cin >> a >> d;

    vector<vector<int>> dp(n + d, vector<int>(n + d));

    for(int i = 1; i < n + d; i++){
        dp[i][0] = dp[i - 1][0] + arr[i];
    }

    for(int i = d; i < n + d; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = max(dp[i - 1][j] + arr[i], dp[i - d][j - 1] + a);
        }
    }

    for(int j = 0; j <= n; j++){
        if(dp[n + d - 1][j] >= m){
            cout << j;
            return 0;
        }
    }

    cout << -1;

    return 0;
}