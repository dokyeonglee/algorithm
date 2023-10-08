#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> arr[i][j];
            if(i != j and arr[i][j] == 0){
                arr[i][j] = 987654321;
            }
        }
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 987654321)));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j][0] = arr[i][j];
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j][k] = min(dp[i][j][k - 1], dp[i][k][k - 1] + dp[k][j][k - 1]);
            }
        }
    }

    while(q--){

        int c, s, e;
        cin >> c >> s >> e;

        int answer = dp[s][e][c - 1];

        if(answer == 987654321){
            answer = -1;
        }

        cout << answer << "\n";

    }

    return 0;
}