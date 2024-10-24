#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, c;
    cin >> n >> m >> c;

    vector<int> arrive_times(n);

    for(auto& arrive_time : arrive_times){
        cin >> arrive_time;
    }

    sort(arrive_times.begin(), arrive_times.end());

    int left = 0;
    int right = arrive_times.back() - arrive_times.front();
    int answer = right;

    while(left <= right){

        int mid = (left + right) / 2;

        int cnt = 1;
        int idx = 0;

        for(int i = 1; i < n; i++){
            if(arrive_times[i] - arrive_times[idx] > mid or i - idx == c){
                cnt++;
                idx = i;
            }
        }

        if(cnt <= m){
            answer = mid;
            right = mid - 1;
        }else{
            left = mid + 1;
        }

    }

    cout << answer;

    return 0;
}