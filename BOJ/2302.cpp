#include <iostream>
#include <vector>

using namespace std;

int solve(const int n, const vector<int>& vip_seats) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int result = 1;
    int prev_vip = 0;

    for (const int seat : vip_seats) {
        result *= dp[seat - prev_vip - 1];
        prev_vip = seat;
    }

    result *= dp[n - prev_vip];
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> vip_seats(m);
    for (int& seat : vip_seats) {
        cin >> seat;
    }

    cout << solve(n, vip_seats) << '\n';
    return 0;
}