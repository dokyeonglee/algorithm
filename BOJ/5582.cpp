#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
    
    int answer = 0;

    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }

    cout << answer;

    return 0;
}