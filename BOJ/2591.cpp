#include <iostream>
#include <vector>

using namespace std;

int solve(string& str, vector<int>& dp, int idx){

    if(idx == str.size()){
        return 1;
    }

    int& ret = dp[idx];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    if(str[idx] == '0'){
        return 0;
    }

    if(idx < str.size() - 1){
        int x = 10 * (str[idx] - '0') + (str[idx + 1] - '0');
        if(x < 35){
            ret += solve(str, dp, idx + 2);
        }
    }

    return ret += solve(str, dp, idx + 1);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    vector<int> dp(str.size() + 1, -1);

    cout << solve(str, dp, 0);

    return 0;
}