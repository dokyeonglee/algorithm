#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long answer = 0;

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i] >> brr[i];
    }

    int left = 0;
    int right = 1e9;

    int min_value = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        long long cnt = 0;
        for(int i = 0; i < n; i++){
            if(brr[i] >= mid){
                cnt += 1 + (brr[i] - mid) / arr[i];
            }
        }
        if(cnt >= k){
            left = mid + 1;
            min_value = mid;
        }else{
            right = mid - 1;
        }
    }

    long long cnt = 0;

    for(int i = 0; i < n; i++){
        if(brr[i] >= min_value){
            long long temp = 1 + (brr[i] - min_value) / arr[i];
            cnt += temp;
            answer += temp * brr[i] - arr[i] * temp * (temp - 1) / 2;
        }
    }
    answer -= min_value * max(0ll, cnt - k);

    cout << answer;

    return 0;
}