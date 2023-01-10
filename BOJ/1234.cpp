#include <iostream>
#include <vector>

using namespace std;

vector<int> fac(11, 1);

long long solve(vector<vector<vector<vector<long long>>>>& dp, int n, int r, int g, int b){

    if(r < 0 or g < 0 or b < 0){
        return 0;
    }

    if(n == 0){
        return 1;
    }

    long long& ret = dp[n][r][g][b];
    if(ret != -1){
        return ret;
    }

    ret = 0;

    ret += solve(dp, n - 1, r - n, g, b);
    ret += solve(dp, n - 1, r, g - n, b);
    ret += solve(dp, n - 1, r, g, b - n);

    if(n % 2 == 0){
        int  f = fac[n] / fac[n / 2] / fac[n / 2];
        ret += solve(dp, n - 1, r - n / 2, g - n / 2, b) * f;
        ret += solve(dp, n - 1, r - n / 2, g, b - n / 2) * f;
        ret += solve(dp, n - 1, r, g - n / 2, b - n / 2) * f;
    }

    if(n % 3 == 0){
        int  f = fac[n] / fac[n / 3] / fac[n / 3] / fac[n / 3];
        ret += solve(dp, n - 1, r - n / 3, g - n /3 , b - n / 3) * f;
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, g, b;
    cin >> n >> r >> g >> b;

    for(int i = 2; i <= 10; i++){
        fac[i] = fac[i - 1] * i;
    }

    vector<vector<vector<vector<long long>>>> dp(n + 5, vector<vector<vector<long long>>>(r + 5, vector<vector<long long>>(g + 5, vector<long long>(b + 5, -1))));

    cout << solve(dp, n, r, g, b);
    
    return 0;
}