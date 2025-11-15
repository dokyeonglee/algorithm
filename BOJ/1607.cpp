#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 9901;

int main() {
    int n;
    cin >> n;

    int dp = 1;

    int p = 2;
    int cnt = 2;
    int temp = 2;

    for (int i = 2; i <= n; ++i) {
        dp = (dp + p) % MOD;
        if (--temp == 0) {
            temp = ++cnt;
            p = 2 * p % MOD;
        }
    }

    cout << dp << '\n';

    return 0;
}