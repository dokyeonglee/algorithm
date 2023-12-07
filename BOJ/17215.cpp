#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int answer = 0;
    int cnt = 0;

    vector<int> score(12);
    vector<int> frame(str.size());

    for(int i = 0; i < str.size(); i++){

        int fr = cnt++ / 2;
        frame[i] = fr;

        int s = 0;

        if(str[i] >= '0' and str[i] <= '9'){
            s = str[i] - '0';
        }else if(str[i] == 'S'){
            s = 10;
            cnt++;
        }else if(str[i] == 'P'){
            s = 10;
            if(i){
                if(str[i - 1] >= '0' and str[i - 1] <= '9'){
                    s -= str[i - 1] - '0';
                }
            }
        }

        score[fr] += s;

        if(i){
            if(str[i - 1] == 'S' or str[i - 1] == 'P'){
                score[frame[i - 1]] += s;
            }
        }
        if(i > 1){
            if(str[i - 2] == 'S'){
                score[frame[i - 2]] += s;
            }
        }
        
    }

    for(int i = 0; i < 10; i++){
        answer += score[i]; 
    }

    cout << answer;

    return 0;
}