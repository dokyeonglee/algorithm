#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<bitset<2001>>> arr(n + 5, vector<bitset<2001>>(m + 5));

    int k;
    cin >> k;

    for(int i = 1; i <= k; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[a][b].set(i);
        arr[c + 1][b].set(i);
        arr[a][d + 1].set(i);
        arr[c + 1][d + 1].set(i);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            arr[i][j] ^= arr[i - 1][j] ^ arr[i][j - 1] ^ arr[i - 1][j - 1];
        }
    }

    vector<vector<bitset<2001>>> dp(n + 5, vector<bitset<2001>>(m + 5));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            auto a = (dp[i - 1][j] | arr[i][j]);
            auto b = (dp[i][j - 1] | arr[i][j]);
            if(i == 1){
                dp[i][j] = b;
            }else if(j == 1){
                dp[i][j] = a;
            }else if(a.count() > b.count()){
                dp[i][j] = b;
            }else{
                dp[i][j] = a;
            }
        }
    }

    cout << dp[n][m].count();

    return 0;
}