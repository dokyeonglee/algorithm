#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str;
    cin >> str;

    vector<vector<bool>> is_palindrome(str.size() + 1, vector<bool>(str.size() + 1));
    for (int i = 1; i <= str.size(); ++i) {
        is_palindrome[i][i] = true;
    }

    for (int i = 1; i + 1 <= str.size(); ++i) {
        is_palindrome[i][i + 1] = (str[i - 1] == str[i]);
    }

    for (int l = 3; l <= str.size(); ++l) {
        for (int i = 1; i + l - 1 <= str.size(); ++i) {
            is_palindrome[i][i + l - 1] = (is_palindrome[i + 1][i + l - 2] & (str[i - 1] == str[i + l - 2]));
        }
    }

    vector<int> dp(str.size() + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= str.size(); ++i) {
        for (int j = i; j >= 1; --j) {
            if (is_palindrome[j][i]) {
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[str.size()] << '\n';

    return 0;
}