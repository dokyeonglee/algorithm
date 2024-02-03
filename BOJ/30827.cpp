#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(n <= k){
        cout << n;
        return 0;
    }

    vector<pair<int, int>> arr(n);
    for(auto& a : arr){
        cin >> a.second >> a.first;
    }

    sort(arr.begin(), arr.end());

    vector<int> end_time(k);

    int answer = 0;

    for(int i = 0; i < n; i++){
        int idx = -1;
        int max_end_time = -1;
        for(int j = 0; j < k; j++){
            if(end_time[j] < arr[i].second){
                if(max_end_time < end_time[j]){
                    idx = j;
                    max_end_time = end_time[j];
                }
            }
        }
        if(idx != -1){
            answer++;
            end_time[idx] = arr[i].first;
        }
    }

    cout << answer;

    return 0;
}