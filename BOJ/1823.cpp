#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& arr, vector<vector<int>>& dp, int left, int right){

    if(left == right){
        return (int)arr.size() * arr[left];
    }

    int& ret = dp[left][right];
    
    if(ret != -1){
        return ret;
    }

    int k = arr.size() - (right - left);
    
    ret = max(k * arr[left] + solve(arr, dp, left + 1, right), k * arr[right] + solve(arr, dp, left, right - 1));

    return ret;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    cout << solve(arr, dp, 0, n - 1);

    return 0;
}