#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int cnt = arr[0] % 2;

    int answer = 0;

    while(right < n){
        if(cnt <= k){
            answer = max(answer, right - left + 1 - cnt);
            cnt += arr[++right] % 2;
        }
        else{
            cnt -= arr[left++] % 2;
        }
    }

    cout << answer;

    return 0;
}