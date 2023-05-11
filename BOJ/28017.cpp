#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(n + 1, vector<int>(m));
    for(int i = 1; i <= n; i++){
        int result = 987654321;
        int result2 = 987654321;
        for(int j = 0; j < m; j++){
            cin >> dp[i][j];
            if(dp[i - 1][j] < result){
                result2 = result;
                result = dp[i - 1][j];
            }else if(dp[i - 1][j] < result2){
                result2 = dp[i - 1][j];
            }
        }
        for(int j = 0; j < m; j++){
            if(dp[i - 1][j] == result){
                dp[i][j] += result2;
            }else{
                dp[i][j] += result;
            }
        }
    }

    cout << *min_element(dp[n].begin(), dp[n].end());

    return 0;
}