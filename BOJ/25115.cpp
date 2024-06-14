#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }

    long long left = 0;
    long long right = arr[n] - 1;

    long long answer = arr[n];

    while(left <= right){
        long long mid = (left + right) / 2;
        int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        long long remain = mid - arr[idx - 1];
        if(arr[idx - 1] < 10 * (arr[idx] - mid)){
            left = mid + 1;
        }else{
            if((arr[n] - mid) * 10 <= mid){
                answer = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
    }

    cout << answer;

    return 0;
}