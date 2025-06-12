#include <iostream>
#include <vector>

using namespace std;

int calculate_lcs_length(const string& str1, const string& str2) {

    const int n = str1.size();
    const int m = str2.size();

    vector<vector<int>> dp(2, vector<int>(m + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i & 1][j] = dp[(i & 1) ^ 1][j - 1] + 1;
            } else {
                dp[i & 1][j] = max(dp[i & 1][j - 1], dp[(i & 1) ^ 1][j]);
            }
        }
    }

    return dp[n & 1][m];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;

    while (cin >> str1 >> str2) {
        cout << calculate_lcs_length(str1, str2) << '\n';
    }

    return 0;
}