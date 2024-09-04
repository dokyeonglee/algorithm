#include <iostream>
#include <vector>

using namespace std;

int lcs(string& str, int idx){

    vector<vector<int>> dp(idx + 1, vector<int>(str.size() - idx + 1));

    for(int i = 1; i <= idx; i++){
        for(int j = idx + 1; j <= str.size(); j++){
            if(str[i - 1] == str[j - 1]){
                dp[i][j - idx] = dp[i - 1][j - idx - 1] + 1;
            }else{
                dp[i][j - idx] = max(dp[i - 1][j - idx], dp[i][j - idx - 1]);
            }
        }
    }

    return dp.back().back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n = str.size();

    int answer = lcs(str, n / 2);

    if(str.size() % 2){
        answer = min(answer, lcs(str, n / 2 + 1));
    }

    cout << n / 2 - answer;

    return 0;
}