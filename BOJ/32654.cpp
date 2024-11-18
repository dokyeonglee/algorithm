#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<bool>> dp(101, vector<bool>(n + 1));

    vector<int> l(n + 1);
    vector<int> r(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
    }

    dp[0][1] = true;

    for(int i = 0; i <= 99; i++){
        for(int j = 1; j <= n; j++){
            if(dp[i][j]){
                dp[i + 1][l[j]] = true;
                dp[i + 1][r[j]] = true;
            }
        }
    }

    for(int i = 10; i <= 99; i++){
        if(!dp[i][1]){
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}