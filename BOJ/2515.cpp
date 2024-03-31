#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    vector<int> dp(n + 1);

    int answer = 0;
    int idx = 1;

    for(int i = 1; i <= n; i++){
        while(idx <= n and arr[i].first - arr[idx].first >= s){
            idx++;
        }
        dp[i] = max(dp[idx - 1] + arr[i].second, dp[i - 1]);
    }

    cout << dp[n];

    return 0;
}