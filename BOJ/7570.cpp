#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    int cnt = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        dp[x] = dp[x - 1] + 1;
        cnt = max(cnt, dp[x]);
    }

    cout << n - cnt;

    return 0;
}