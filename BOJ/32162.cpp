#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> answer;

    for(int i = 1; i <= 200000; i++){
        int cnt = 0;
        int temp = i;
        while(temp % 3 == 0){
            cnt++;
            temp /= 3;
        }
        while(temp % 5 == 0){
            cnt--;
            temp /= 5;
        }
        if(cnt % 3 == 0){
            answer.push_back(i);
        }
    }

    int t;
    cin >> t;

    while(t--){
        int idx;
        cin >> idx;
        cout << answer[--idx] << "\n";
    } 

    return 0;
}