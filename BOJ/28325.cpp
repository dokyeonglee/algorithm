#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);

    long long answer = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        answer += arr[i];
    }

    if(answer == 0){
        cout << n / 2;
        return 0;
    }    

    int cnt = 0;

    int idx = 0;
    while(idx < n and arr[idx] == 0){
        idx++;
    }

    rotate(arr.begin(), arr.begin() + idx, arr.end());

    for(int i = 0; i < n; i++){
        if(arr[i]){
            answer += (cnt + 1) / 2;
            cnt = 0;
        }else{
            cnt++;
        }
    }

    answer += (cnt + 1) / 2;

    cout << answer;

    return 0;
}