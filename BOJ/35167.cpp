#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n + 2);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<int> dp(n + 2);
    vector<int> dp2(n + 2);

    for (int i = 1; i <= n; ++i) {
        dp[i] = min(dp[i - 1] + 1, arr[i]);
    }

    for (int i = n; i >= 1; --i) {
        dp2[i] = min(dp2[i + 1] + 1, arr[i]);
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        answer = max(answer, min(dp[i], dp2[i]));
    }

    cout << answer;

    return 0;
}