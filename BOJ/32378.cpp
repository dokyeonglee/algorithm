#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k, s;
    cin >> n >> k >> s;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    if(k > 36 or (1ll << k) * s - (n - k) * 500 > 1e11){
        cout << "MEGA";
    }else{

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));

        dp[0][0] = s;

        long long answer = -1;

        for(int i = 1; i <= n; i++){

            long long result = 0;

            if(dp[i - 1][0] > 0){
                dp[i][0] = dp[i - 1][0] + arr[i];
                result = dp[i][0];
            }

            int x = min(i, k);

            for(int j = 1; j <= x; j++){
                if(dp[i - 1][j - 1] > 0){
                    dp[i][j] = 2 * dp[i - 1][j - 1];
                }
                if(dp[i - 1][j] > 0){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i]);
                }
                result = max(result, dp[i][j]);
            }

            if(result <= 0){
                cout << -1;
                return 0;
            }else{
                answer = result;
            }

            if(answer - 500 * (n - i) > 1e11){
                cout << "MEGA";
                return 0;
            }

        }

        cout << answer;

    }

    return 0;
}