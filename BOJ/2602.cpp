#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<string> stone(2);
    cin >> stone[0] >> stone[1];

    vector<vector<long long>> dp(str.size() + 1, vector<long long>(stone[0].size() + 1));
    vector<vector<long long>> dp2(str.size() + 1, vector<long long>(stone[1].size() + 1));

    fill(dp[0].begin(), dp[0].end(), 1);
    fill(dp2[0].begin(), dp2[0].end(), 1);

    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= stone[0].size(); j++){
            dp[i][j] = dp[i][j - 1] + (stone[(i - 1) % 2][j - 1] == str[i - 1]) * dp[i - 1][j - 1];
        }
    }

    for(int i = 1; i <= str.size(); i++){
        for(int j = 1; j <= stone[1].size(); j++){
            dp2[i][j] = dp2[i][j - 1] + (stone[i % 2][j - 1] == str[i - 1]) * dp2[i - 1][j - 1];
        }
    }

    cout << dp[str.size()][stone[0].size()] + dp2[str.size()][stone[1].size()];

    return 0;
}