#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> arr(n);
    for(auto& a : arr){
        cin >> a;
    }

    vector<int> front_word(26, 1e9);
    vector<int> back_word(26, 1e9);

    for(int i = 0; i < arr[0].size(); i++){
        front_word[arr[0][i] - 'a'] = min(front_word[arr[0][i] - 'a'], (int)arr[0].size() - 1 - i);
        back_word[arr[0][i] - 'a'] = min(back_word[arr[0][i] - 'a'], i);
    }

    int answer = 1e9;

    for(int i = 1; i < n; i++){
        for(int j = 0; j < arr[i].size(); j++){
            answer = min(answer, front_word[arr[i][j] - 'a'] + j);
            answer = min(answer, (int)arr[i].size() - 1 - j + back_word[arr[i][j] - 'a']);
        }
        for(int j = 0; j < arr[i].size(); j++){
            front_word[arr[i][j] - 'a'] = min(front_word[arr[i][j] - 'a'], (int)arr[i].size() - 1 - j);
            back_word[arr[i][j] - 'a'] = min(back_word[arr[i][j] - 'a'], j);
        }
    }

    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;

    return 0;
}