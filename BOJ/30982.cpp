#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int p;
    cin >> p;

    if(m < arr[p]){
        cout << "NO";
        return 0;
    }

    if(m == arr[p]){
        cout << "YES";
        return 0;
    }

    m -= arr[p];

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    vector<vector<bool>> dp2(n + 1, vector<bool>(m + 1));

    dp[p][0] = true;

    for(int i = p - 1; i >= 1; i--){
        dp[i][0] = true;
        for(int j = 0; j <= m; j++){
            if(j < arr[i]){
                dp[i][j] = dp[i + 1][j];
            }else{
                dp[i][j] = (dp[i + 1][j] | dp[i + 1][j - arr[i]]);
            }
        }
    }

    dp2[p][0] = true;

    for(int i = p + 1; i <= n; i++){
        dp2[i][0] = true;
        for(int j = 0; j <= m; j++){
            if(j < arr[i]){
                dp2[i][j] = dp2[i - 1][j];
            }else{
                dp2[i][j] = (dp2[i - 1][j] | dp2[i - 1][j - arr[i]]);
            }
        }
    }

    for(int i = 0; i <= m; i++){
        int x = -1;
        for(int j = p; j >= 1; j--){
            if(dp[j][i]){
                x = j;
                break;
            }
        }
        if(x != -1){
            int y = -1;
            for(int j = p; j <= n; j++){
                if(dp2[j][m - i]){
                    y = j;
                    break;
                }
            }
            if(y != -1 and 2 * min(y - p, p - x) + max(y - p, p - x) <= t){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}