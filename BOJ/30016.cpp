#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<vector<int>> arr(n + 1, vector<int>(t + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= t; j++){
            cin >> arr[i][j];
        }
    }

    vector<int> d(t + 1);
    for(int i = 0; i <= t; i++){
        cin >> d[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(t + 1));
 
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= t; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + arr[i][k]);
            }
        }
    }

    vector<int> v(n + 1);

    int now = 0;
    int answer = -1e9;
    int tt = t;

    for(int i = 0; i <= t; i++){
        if(answer < dp[n][i] - d[i]){
            answer = dp[n][i] - d[i];
            now = dp[n][i];
            tt = i;
        }
    }

    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= tt; j++){
            if(dp[i - 1][tt - j] + arr[i][j] == now){
                v[i] = j;
                tt -= j;
                now -= arr[i][j];
                break;
            }
        }
    }

    cout << answer << "\n";
    for(int i = 1; i <= n; i++){
        cout << v[i] << " ";
    }

    return 0;
}