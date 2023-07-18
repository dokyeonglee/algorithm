#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1e9 + 7;

    int n;
    cin >> n;

    vector<int> c(4);
    c[0] = 1;
    c[1] = n;
    c[2] = n * (n - 1) / 2;
    c[3] = c[2] * (n - 2) / 3;

    vector<long long> dp(n + 5);
    dp[2] = 1;

    for(int i = 3; i <= n; i++){
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % mod;
    }

    cout << dp[n - n % 4] * c[n % 4] % mod;

    return 0;
}