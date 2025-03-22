#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    string target;
    cin >> target;

    vector<int> char_idx(26);

    for(int i = 0; i < target.size(); i++){
        char_idx[target[i] - 'a'] = i + 1;
    }

    vector<int> dp(target.size() + 1);

    dp[0] = 1e9;

    for(int i = 0; i < str.size(); i++){
        int idx = char_idx[str[i] - 'a'];
        if(idx){
            if(dp[idx - 1] > dp[idx]){
                dp[idx]++;
            }
        }
    }

    cout << dp[target.size()];

    return 0;

}