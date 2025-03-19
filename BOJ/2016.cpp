#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_partner(vector<vector<int>>& boy, vector<vector<int>> girl){

    vector<bool> is_matched(6);
    vector<int> partner(6);

    while(1){
        bool is_completed = true;
        for(int i = 1; i <= 5; i++){
            if(!is_matched[i]){
                int b = girl[i].back();
                girl[i].pop_back();
                if(partner[b] == 0){
                    partner[b] = i;
                    is_matched[i] = true;
                }else{
                    is_completed = false;
                    if(boy[b][i] < boy[b][partner[b]]){
                        is_matched[partner[b]] = false;
                        partner[b] = i;
                        is_matched[i] = true;
                    }
                }
            }
        }
        if(is_completed){
            break;
        }
    }

    return partner[1];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        vector<vector<int>> boy(6, vector<int>(6));
        vector<vector<int>> girl(6, vector<int>(6));

        for(int i = 1; i <= 5; i++){
            boy[1][i] = i;
        }

        for(int i = 2; i <= 5; i++){
            for(int j = 1; j <= 5; j++){
                int x;
                cin >> x;
                boy[i][x - 5] = j;
            }
        }

        for(int i = 1; i <= 5; i++){
            for(int j = 5; j >= 1; j--){
                cin >> girl[i][j];
            }
        }

        int original_parter = get_partner(boy, girl);

        if(original_parter == 1){
            cout << "NO\n";
        }else{
            bool possible = false;
            do{
                int partner = get_partner(boy, girl);
                if(partner < original_parter){
                    possible = true;
                    break;
                }
            }while(next_permutation(boy[1].begin(), boy[1].end()));
            if(possible){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }

    }

    return 0;

}