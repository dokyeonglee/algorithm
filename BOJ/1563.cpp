#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<vector<int>>>& dp, int n, int late, int absent){

    if(late == 2 or absent == 3){
        return 0;
    }   

    if(n == dp.size()){
        return 1;
    }

    int& ret = dp[n][late][absent];
    if(ret != -1){
        return ret;
    }

    ret = (solve(dp, n + 1, late, 0) + solve(dp, n + 1, late + 1, 0) + solve(dp, n + 1, late, absent + 1)) % 1000000;

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    cout << solve(dp, 0, 0, 0);

    return 0;
}