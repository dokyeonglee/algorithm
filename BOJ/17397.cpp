#include <iostream>
#include <vector>

using namespace std;

int get_deprivation(int x, int y){
    return x > y ? (x - y) * (x - y) : 0;
}

int solve(vector<int>& arr, vector<vector<vector<int>>>& dp, int idx, int budget, int extra){

    if(idx == arr.size() - 1){
        return 0;
    }

    int& ret = dp[idx][budget][extra];

    if(ret != -1){
        return ret;
    }

    ret = 1e9;

    for(int i = 0; i <= min(budget, 10); i++){
        ret = min(ret, solve(arr, dp, idx + 1, budget - i, i) + get_deprivation(arr[idx] + extra, arr[idx + 1] + i));
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(11, -1)));

    cout << solve(arr, dp, 1, m, 0);

    return 0;
}