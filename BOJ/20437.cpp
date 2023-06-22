#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        string str;
        int k;

        cin >> str >> k;

        vector<vector<int>> indices(26);

        int answer = 987654321;
        int answer2 = -1;

        for(int i = 0; i < str.size(); i++){
            indices[str[i] - 'a'].push_back(i);
        }

        for(int i = 0; i < 26; i++){
            for(int j = 0; j + k <= indices[i].size(); j++){
                answer = min(answer, indices[i][j + k - 1] - indices[i][j] + 1);
                answer2 = max(answer2, indices[i][j + k - 1] - indices[i][j] + 1);
            }
        }

        if(answer == 987654321){
            cout << "-1\n";
        }else{
            cout << answer << " " << answer2 << "\n";
        }
    }

    return 0;
}