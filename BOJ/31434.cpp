#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> brr(n);

    int max_b = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i] >> brr[i];
        max_b = max(max_b, brr[i]);
    }

    vector<vector<int>> dp(k + 1, vector<int>(2502, -1));

    dp[1][1] = 1;

    for(int i = 1; i < k; i++){
        for(int j = 1; j < dp[i].size(); j++){
            if(dp[i][j] != -1){
                dp[i + 1][j] = dp[i][j] + j;
                for(int x = 0; x < n; x++){
                    if(j + brr[x] < dp[i].size() and dp[i][j] >= arr[x]){
                        dp[i + 1][j + brr[x]] = max(dp[i + 1][j + brr[x]], dp[i][j] - arr[x]);
                    }
                }
            }
        }
    }

    int answer = 0;

    for(int i = 0; i < dp[k].size(); i++){
        answer = max(answer, dp[k][i]);
    }

    cout << answer;

    return 0;
}