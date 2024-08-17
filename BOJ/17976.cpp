#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<long long, long long>> arr(n);
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    sort(arr.begin(), arr.end());

    int answer = 1;

    long long left = 1;
    long long right = 2e9;

    while(left <= right){
        long long mid = (left + right) / 2;
        long long now = arr[0].first;
        bool check = true;
        for(int i = 1; i < n; i++){
            if(now + mid <= arr[i].first + arr[i].second){
                now = max(now + mid, arr[i].first);
            }else{
                check = false;
                break;
            }
        }
        if(check){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}