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

    for(char& ch : str){
        if(ch == 'A'){
            cnt++;
        }else if(ch == 'B' and cnt){
            cnt--;
            answer++;
        }
    }

    cnt = 0;

    int cnt_b = 0;

    for(char& ch : str){
        if(ch == 'B'){
            cnt++;
            cnt_b++;
        }else if(ch == 'C' and cnt){
            cnt--;
            answer++;
        }
    }

    cout << min(cnt_b, answer);

    return 0;
}