#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& arr, vector<vector<vector<int>>>& dp, int idx, int current_tool, int remain_tools){

    if(idx == arr.size()){
        return 0;
    }

    int& ret = dp[idx][current_tool][remain_tools];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    if(arr[idx] == current_tool){
        ret = solve(arr, dp, idx + 1, current_tool, remain_tools) + 1;
    }else{
        ret = solve(arr, dp, idx + 1, current_tool, remain_tools);
        if(remain_tools & (1 << arr[idx])){
            ret = max(ret, solve(arr, dp, idx + 1, arr[idx], remain_tools & ~(1 << current_tool)) + 1);
        }
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(8, -1)));

    vector<int> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    int answer = 0;

    for(int i = 0; i < 3; i++){
        answer = max(answer, solve(arr, dp, 0, i, 7));
    }

    cout << answer;

    return 0;
}