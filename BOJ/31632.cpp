#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string vegetable;
        cin >> vegetable;

        int check = 0;

        for(auto& v : vegetable){
            if(v == 'G'){
                check |= 1;
            }else if(v == 'O'){
                check |= 2;
            }else if(v == 'D'){
                check |= 4;
            }
        }

        string result;
        cin >> result;

        int draw_cnt = 0;
        int win_cnt = 0;

        for(int i = 0; i < n; i++){
            if(result[i] == 'W'){
                win_cnt++;
            }else if(result[i] == 'D'){
                draw_cnt++;
            }
        }

        if(draw_cnt == 0){
            if(win_cnt == 0 or win_cnt == n or check == 7){
                cout << "NO\n";
            }else{
                char win_vegetable = 'G';
                if(check == 6){
                    win_vegetable = 'O';
                }else if(check == 5){
                    win_vegetable = 'D';
                }else if(check != 3){
                    for(int i = 0; i < n; i++){
                        if(vegetable[i] != '?'){
                            if(result[i] == 'W'){
                                win_vegetable = vegetable[i];
                            }else{
                                win_vegetable = (vegetable[i] == 'G' ? 'D' : (vegetable[i] == 'O' ? 'G' : 'O'));
                            }
                            break;
                        }
                    }
                }
                bool check2 = true;
                for(int i = 0; i < n; i++){
                    if(!((result[i] == 'W' and (vegetable[i] == win_vegetable or vegetable[i] == '?'))
                        or (result[i] == 'L' and vegetable[i] != win_vegetable))){
                            check2 = false;
                            break;
                    }
                }
                if(check2){
                    for(int i = 0; i < n; i++){
                        if(vegetable[i] == '?'){
                            if(result[i] == 'W'){
                                vegetable[i] = win_vegetable;
                            }else if(result[i] == 'L'){
                                vegetable[i] = (win_vegetable == 'G' ? 'O' : (win_vegetable == 'O' ? 'D' : 'G'));
                            }
                        }
                    }
                    cout << "YES\n";
                    cout << vegetable << "\n";
                }else{
                    cout << "NO\n";
                }
            }
        }else if(draw_cnt == n){
            char fill = 'G';
            if(check == 2 or check == 5){
                fill = 'O';
            }else if(check == 4 or check == 3){
                fill = 'D';
            }
            for(int i = 0; i < n; i++){
                if(vegetable[i] == '?'){
                    vegetable[i] = fill;
                }
            }
            cout << "YES\n";
            cout << vegetable << "\n";
        }else{
            cout << "NO\n";
        }

    }

    return 0;
}