#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> dp2(n + 1, vector<long long>(n + 1));

    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int j = 1; j <= i; j++){
            cin >> dp[i][j];
            sum += dp[i][j];
            dp2[i][j] = dp2[i - 1][j] + sum;
            dp[i][j] = dp[i - 1][j - 1] + sum;
        }
    }

    int q;
    cin >> q;

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        cout << dp[x + z - 1][y + z - 1] - dp[x - 1][y - 1] - (dp2[x + z - 1][y - 1] - dp2[x - 1][y - 1]) << "\n";
    }

    return 0;

}