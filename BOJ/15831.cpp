#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b, w;
    cin >> n >> b >> w;

    string str;
    cin >> str;

    int b_cnt = 0;
    int w_cnt = 0;

    int answer = 0;

    int left = 0;
    int right = -1;

    while(right < n - 1){

        b_cnt += str[++right] == 'B';
        w_cnt += str[right] == 'W';

        if(b_cnt > b){
            b_cnt -= str[left] == 'B';
            w_cnt -= str[left++] == 'W';
        }

        if(w_cnt >= w and b_cnt <= b){
            answer = max(answer, right - left + 1);
        }

    }

    cout << answer;

    return 0;
}