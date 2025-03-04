#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<vector<int>> cnt_zero(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> dp[i][j];
        }
    }

    int m;
    cin >> m;

    vector<int> arr(m + 1);
    
    for(int i = 1; i <= m; i++){
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend() - 1);

    for(int i = 1; i <= m; i++){
        arr[i] += arr[i - 1];
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j] == 0){
                cnt_zero[i][j] = 1;
            }
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            cnt_zero[i][j] += cnt_zero[i - 1][j] + cnt_zero[i][j - 1] - cnt_zero[i - 1][j - 1];
        }
    }
    
    int answer = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int max_length = n - max(i, j) + 1;
            int r = i + max_length - 1;
            int c = j + max_length - 1;
            while(max_length--){
                int number_of_zero = cnt_zero[r][c] - cnt_zero[i - 1][c] - cnt_zero[r][j - 1] + cnt_zero[i - 1][j - 1];
                int sum_of_value = dp[r][c] - dp[i - 1][c] - dp[r][j - 1] + dp[i - 1][j - 1];
                if(number_of_zero <= m){
                    answer = max(answer, sum_of_value + arr[number_of_zero]);
                    break;
                }
                r--;
                c--;
            }
        }
    }

    cout << answer;

    return 0;

}