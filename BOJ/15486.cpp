#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> dp(n + 5);

    int answer = 0;

    for(int i = 1; i <= n + 1; i++){
        answer = max(answer, dp[i]);
        if(i + arr[i].first > n + 1){
            continue;
        }
        dp[i + arr[i].first] = max(dp[i + arr[i].first], answer + arr[i].second);
    }

    cout << answer;

    return 0;
}