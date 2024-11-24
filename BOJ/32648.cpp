#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> arr(n + 1, vector<char>(m + 1));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dp(n + 5, vector<int>(m + 5));
    vector<vector<int>> dp2(n + 5, vector<int>(m + 5));

    string zoac = "ZOAC";

    for(int k = 0; k < 4; k++){

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if(arr[i][j] == zoac[k]){
                    ++dp[i][j];
                }
            }
        }
    
        for(int i = n; i >= 1; i--){
            for(int j = m; j >= 1; j--){
                dp2[i][j] = max(dp2[i + 1][j], dp2[i][j + 1]);
                if(arr[i][j] == zoac[k]){
                    ++dp2[i][j];
                }
            }
        }

        int answer = 0;

        for(int i = 1; i <= n; i++){
            answer = max(answer, dp[i][m] + dp2[i + 1][1]);
        }

        for(int i = 1; i <= m; i++){   
            answer = max(answer, dp[n][i] + dp2[1][i + 1]);
        }

        cout << answer << " ";

    }

    return 0;
}