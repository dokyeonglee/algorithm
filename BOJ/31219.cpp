#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double distance(pair<long long, long long>& a, pair<long long, long long>& b){
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

double solve(vector<pair<long long, long long>>& arr, vector<vector<double>>& dp, int now, int visited){

    int n = arr.size();

    if(visited == (1 << n) - 1){
        return distance(arr[now], arr[0]);
    }

    double& ret = dp[now][visited];

    if(ret != 1e18){
        return ret;
    }

    for(int i = 0; i < n; i++){
        if(visited & (1 << i)){
            continue;
        }
        ret = min(ret, solve(arr, dp, i, visited | (1 << i)) + distance(arr[now], arr[i]));
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    vector<vector<double>> dp(n + 1, vector<double>(1 << n, 1e18));


    cout << fixed;
    cout.precision(12);
    cout << solve(arr, dp, 0, 1);

    return 0;
}