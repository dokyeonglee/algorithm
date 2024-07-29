#include <iostream>
#include <vector>

using namespace std;

int cost(string& str, int idx, string& word){

    int result = 0;

    vector<int> cnt(26);

    for(int i = 0; i < word.size(); i++){
        if(str[idx + i] != word[i]){
            result++;
        }
        cnt[str[idx + i] - 'a']++;
        cnt[word[i] - 'a']--;
    }

    for(int i = 0; i < 26; i++){
        if(cnt[i]){
            return 1e9;
        }
    }

    return result;

}

int solve(string& str, vector<string>& words, vector<int>& dp, int idx){

    if(idx == str.size()){
        return 0;
    }

    int& ret = dp[idx];

    if(ret != -1){
        return ret;
    }

    ret = 1e9;

    for(auto& word : words){
        if(idx + word.size() > str.size()){
            continue;
        }
        ret = min(ret, cost(str, idx, word) + solve(str, words, dp, idx + word.size()));
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int n;
    cin >> n;

    vector<string> words(n);
    for(auto& word : words){
        cin >> word;
    }

    vector<int> dp(str.size() + 1, -1);

    int answer = solve(str, words, dp, 0);

    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;

    return 0;
}