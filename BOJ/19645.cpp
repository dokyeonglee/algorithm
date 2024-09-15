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

    vector<vector<bool>> dp(sum + 1, vector<bool>(sum + 1));

    dp[0][0] = true;

    int temp = 0;

    for(int i = 1; i <= n; i++){
        temp += arr[i];
        for(int j = temp; j >= 0; j--){
            for(int k = temp; k >= 0; k--){
                if(dp[j][k]){
                    dp[j + arr[i]][k] = true;
                    dp[j][k + arr[i]] = true;
                }
            }
        }
    }

    int answer = 0;

    for(int i = 0; i <= sum; i++){
        for(int j = 0; j <= i; j++){
            if(dp[i][j] and sum - i - j <= j){
                answer = max(answer, sum - i - j);
            }
        }
    }

    cout << answer;


    return 0;
}