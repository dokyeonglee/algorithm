#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = 10000;
    int answer = 0;

    while(left <= right){
        int mid = (left + right) / 2;
        int now = 0;
        int cnt = 1;
        int min_value = arr[0];
        int max_value = arr[0];
        for(int i = 1; i < n; i++){
            min_value = min(min_value, arr[i]);
            max_value = max(max_value, arr[i]);
            if(max_value - min_value > mid){
                cnt++;
                max_value = arr[i];
                min_value = arr[i];
            }
        }
        if(cnt <= m){
            right = mid - 1;
            answer = mid;
        }else{
            left = mid + 1;
        }
    }

    cout << answer;

    return 0;
}