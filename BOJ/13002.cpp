#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> happiness(n);
    for (int i = 0; i < n; i++) {
        cin >> happiness[i];
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            dp[j + 1] = max(dp[j + 1], dp[j] + happiness[j] * i);
            dp[j] += happiness[n - i + j] * i;
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}