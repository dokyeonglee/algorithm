#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> dp(n + 1);

    int temp = arr[1];

    dp[1] = -1e9;

    for(int i = 2; i <= n - 2; i++){
        dp[i] = max(dp[i - 1], arr[i] - temp);
        temp = min(temp, arr[i]);
    }

    int answer = -1e9;
    int dp2 = -1e9;

    temp = arr[n];
    
    for(int i = n - 1; i > 2; i--){
        dp2 = max(dp2, temp - arr[i]);
        answer = max(answer, dp2 + dp[i - 1]);
        temp = max(temp, arr[i]);
    }

    cout << answer;

    return 0;
}