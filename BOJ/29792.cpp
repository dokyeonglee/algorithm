#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.rbegin(), arr.rend());

    vector<pair<long long, long long>> boss(k + 1);
    for(int i = 1; i <= k; i++){
        cin >> boss[i].first >> boss[i].second;
    }

    long long answer = 0;

    for(int i = 0; i < m; i++){
        vector<vector<long long>> dp(k + 1, vector<long long>(901));
        for(int j = 1; j <= k; j++){
            long long cost = (boss[j].first + arr[i] - 1) / arr[i];
            for(int x = 0; x <= 900; x++){
                if(x < cost){
                    dp[j][x] = dp[j - 1][x];
                }else{
                    dp[j][x] = max(dp[j - 1][x], dp[j - 1][x - cost] + boss[j].second);
                }
            }
        }
        answer += dp[k][900];
    }

    cout << answer;

    return 0;
}