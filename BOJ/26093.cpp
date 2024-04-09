#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(n + 1, vector<int>(k + 1));
    vector<vector<int>> dp(arr);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            cin >> arr[i][j];
        }
    }

    int largest_index = 0;
    int second_largest_index = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){

            if(j == largest_index){
                dp[i][j] = dp[i - 1][second_largest_index];
            }else{
                dp[i][j] = dp[i - 1][largest_index];
            }

            dp[i][j] += arr[i][j];

        }

        largest_index = 0;
        second_largest_index = 0;

        for(int j = 1; j <= k; j++){

            if(dp[i][j] > dp[i][largest_index]){
                second_largest_index = largest_index;
                largest_index = j;
            }else{
                if(dp[i][second_largest_index] < dp[i][j]){
                    second_largest_index = j;
                }
            }

        }

    }

    cout << dp[n][largest_index];

    return 0;
}