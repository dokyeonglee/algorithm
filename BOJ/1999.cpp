#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b, q;
    cin >> n >> b >> q;

    vector<vector<int>> arr(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, -1e9));
    vector<vector<int>> dp2(n, vector<int>(n, 1e9));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n - b; j++){
            for(int k = j; k < j + b; k++){
                dp[i][j] = max(dp[i][j], arr[i][k]);
                dp2[i][j] = min(dp2[i][j], arr[i][k]);
            }
        }
    }

    for(int i = 0; i <= n - b; i++){
        for(int j = 0; j <= n - b; j++){
            for(int k = i; k < i + b; k++){
                dp[i][j] = max(dp[i][j], dp[k][j]);
                dp2[i][j] = min(dp2[i][j], dp2[k][j]);
            }
        }
    }

    while(q--){
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        int max_value = dp[r][c];
        int min_value = dp2[r][c];
        cout << max_value - min_value << "\n";
    }

    return 0;

}