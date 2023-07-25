#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr(7);
    for(int i = 1; i < 7; i++){
        cin >> arr[i];
    }

    int answer = arr[6];

    answer += arr[5];
    arr[1] -= min(arr[1],  11 * arr[5]);

    answer += arr[4];
    if(arr[2] > 5 * arr[4]){
        arr[2] -= 5 * arr[4];
    }else{
        arr[1] -= min(arr[1], 20 * arr[4] - 4 * arr[2]);
        arr[2] = 0;
    }

    answer += (arr[3] + 3) / 4;
    arr[3] %= 4;

    if(arr[3]){
        if(arr[2] < 7 - 2 * arr[3]){
            arr[1] -= min(arr[1], 36 - 9 * arr[3] - 4 * arr[2]);
            arr[2] = 0;
        }else{
            arr[2] -= min(arr[2], 7 - 2 * arr[3]);
            arr[1] -= min(arr[1], 8 - arr[3]);
        }
    }

    answer += (arr[2] + 8) / 9;
    arr[2] %= 9;

    if(arr[2]){
        arr[1] -= min(arr[1], 36 - 4 * arr[2]);
    }

    answer += (arr[1] + 35) / 36;

    cout << answer;

    return 0;
}