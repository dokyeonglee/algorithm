#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<vector<int>> adj(26);
    vector<vector<int>> dp(n + 1, vector<int>(26));
    for (int i = 0; i < k; ++i) {
        string str;
        cin >> str;
        adj[str[1] - 'a'].push_back(str[0] - 'a');
        ++dp[2][str[1] - 'a'];
    }

    for (int i = 3; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (const int x : adj[j]) {
                dp[i][j] += dp[i - 1][x];
                if (dp[i][j] >= MOD) {
                    dp[i][j] -= MOD;
                }
            }
        }
    }

    int answer = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            answer += dp[i][j];
            if (answer >= MOD) {
                answer -= MOD;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}