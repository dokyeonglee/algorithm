#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> coin(n + 1);
        for(int i = 1; i <= n; i++){
            cin >> coin[i];
        }
        int m;
        cin >> m;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = coin[i]; j <= m; j++){
                dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[m] << "\n";
    }

    return 0;
}