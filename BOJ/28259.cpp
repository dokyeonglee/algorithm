#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h, k;
    cin >> n >> h >> k;

    vector<bool> check(500);
    for(int i = 0; i < k; i++){
        int x;
        cin >> x;
        check[x] = true;
    }

    vector<vector<long long>> dp(h + 1, vector<long long>(n, 9e18));

    for(int i = 0; i < n; i++){
        dp[0][i] = !check[i];
    }

    for(int i = 1; i <= h; i++){
        for(int a = 0; a < n; a++){
            for(int b = 0; b < n; b++){
                dp[i][a] = min(dp[i][a], dp[i - 1][b] + dp[i - 1][(a - b + n) % n]);
            }
            dp[i][a] += !check[a];
        }
    }

    long long answer = 9e18;

    for(int i = 0; i < n; i++){
        answer = min(answer, dp[h][i]);
    }

    cout << answer;

    return 0;
}