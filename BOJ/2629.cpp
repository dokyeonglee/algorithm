#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    int sum = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));

    dp[0][0] = true;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= sum; j++){
            dp[i][j] = (dp[i][j] | dp[i - 1][j]);
            dp[i][j] = (dp[i][j] | dp[i - 1][abs(j - arr[i])]);
            if(j + arr[i] <= sum){
                dp[i][j] = (dp[i][j] | dp[i - 1][j + arr[i]]);
            }
        }
    }

    int q;
    cin >> q;

    while(q--){
        int b;
        cin >> b;
        if(sum < b){
            cout << "N ";
        }else if(dp[n][b]){
            cout << "Y ";
        }else{
            cout << "N ";
        }
    }

    return 0;
}