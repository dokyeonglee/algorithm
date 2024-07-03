#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> arr(m);
    
    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    sort(arr.begin(), arr.end());

    long long answer = 0;

    long long left = 0;
    long long right = arr.back().second;

    while(left <= right){
        auto mid = (left + right) / 2;
        int cnt = 1;
        long long now = arr[0].first;
        int idx = 0;
        for(int i = 0; i < m; i++){
            while(now + mid <= arr[i].second){
                now = max(now + mid, arr[i].first);
                cnt++;
            }
        }
        if(cnt >= n){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    cout << answer;

    return 0;
}