#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int solve(unordered_map<long long, int>& dp, long long n){

    if(n <= 1){
        return 0;
    }

    if(dp.count(n)){
        return dp[n];
    }

    dp[n] = min(solve(dp, n / 3) + n % 3, solve(dp, n / 2) + n % 2) + 1;

    return dp[n];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    unordered_map<long long, int> dp;
    
    cout << solve(dp, n);

    return 0;

}