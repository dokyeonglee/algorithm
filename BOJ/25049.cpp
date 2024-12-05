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

    vector<long long> dp(n + 2);
    vector<long long> dp2(n + 2);

    long long local = 0;

    for(int i = 1; i <= n; i++){
        local = max(0ll, local) + arr[i];
        dp[i] = max(dp[i - 1], local);
    }

    local = 0;

    for(int i = n; i >= 1; i--){
        local = max(0ll, local) + arr[i];
        dp2[i] = max(dp2[i + 1], local);
    }

    long long answer = 0;
    long long sum = arr[n];

    for(int i = 1; i < n; i++){
        answer = max(answer, dp[i] + dp2[i + 1]);
        sum += arr[i];
    }

    answer += sum;

    cout << answer;

    return 0;
}