#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    cin >> n >> b;

    int idx = -1;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == b){
            idx = i;
        }
    }

    vector<int> cnt(2e5 + 1);

    int temp = 0;

    cnt[1e5] = 1;

    for(int i = idx + 1; i < n; i++){
        if(arr[i] > b){
            temp++;
        }else{
            temp--;
        }
        cnt[temp + 1e5]++;
    }

    long long answer = cnt[1e5];

    temp = 0;

    for(int i = idx - 1; i >= 0; i--){
        if(arr[i] > b){
            temp--;
        }else{
            temp++;
        }
        answer += cnt[temp + 1e5];
    }

    cout << answer;

    return 0;
}