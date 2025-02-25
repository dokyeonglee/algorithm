#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int answer = 0;

    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int r = 1; r <= i; r++){
                for(int c = 1; c <= j; c++){
                    if(arr[r][c] < arr[i][j]){
                        dp[i][j] = max(dp[i][j], dp[r][c]);
                    }
                }
            }
            dp[i][j] += 1;
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;

    return 0;

}