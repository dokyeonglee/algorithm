#include <iostream>
#include <vector>

using namespace std;

int dr[] = {-1, 0, 1, 1, 0, -1};
int dc[] = {1, 2, 1, -1, -2, -1};

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<vector<int>>> dp(15, vector<vector<int>>(61, vector<int>(61)));

    dp[0][30][30] = 1;

    for(int i = 1; i <= 14; i++){
        for(int r = 0; r <= 60; r++){
            for(int c = 0; c <= 60; c++){
                for(int k = 0; k < 6; k++){
                    int next_r = r + dr[k];
                    int next_c = c + dc[k];
                    if(next_r < 0 or next_r > 60 or next_c < 0 or next_c > 60){
                        continue;
                    }
                    dp[i][r][c] += dp[i - 1][next_r][next_c];
                }
            }
        }
    }

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        cout << dp[n][30][30] << "\n";
    }

    return 0;

}