#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    string str;
    cin >> str;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        if(str[i] == 'R'){
            arr[i] = 0;
        }else if(str[i] == 'G'){
            arr[i] = 1;
        }else{
            arr[i] = 2;
        }
    }

    int answer = 987654321;

    for(int i = 0; i < 3; i++){
        int result = 0;
        vector<int> temp(arr);
        for(int j = 0; j < n - 2; j++){
            int cnt = (i - temp[j] + 3) % 3;
            result += cnt;
            for(int k = 0; k < 3; k++){
                temp[j + k] = (temp[j + k] + cnt) % 3;
            }
        }
        if(temp[n - 2] == i and temp[n - 1] == i){
            answer = min(answer, result);
        }
    }

    if(answer == 987654321){
        answer = -1;
    }

    cout << answer;

    return 0;
}