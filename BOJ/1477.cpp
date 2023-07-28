#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<int> arr(n + 1);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    arr[n] = l;

    sort(arr.begin(), arr.end());

    for(int i = n; i >= 1; i--){
        arr[i] -= arr[i - 1];
    }

    int left = 1;
    int right = l;

    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        int cnt = 0;
        for(int i = 0; i <= n; i++){
            cnt += (arr[i] - 1) / mid;
        }
        if(cnt > m){
            left = mid + 1;
        }else{
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}