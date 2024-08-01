#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    vector<int> pos(1e6 + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));

    long long answer = 0;

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int idx = 2 * arr[i] - arr[j] >= 0 ? pos[2 * arr[i] - arr[j]] : 0;
            if(idx){
                dp[i][j] = dp[idx][i] + arr[j];
                answer = max(answer, dp[i][j]);
            }else{
                dp[i][j] = arr[i] + arr[j];
            }
        }
    }

    cout << answer;

    return 0;
}