#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    vector<pair<long long, long long>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].second >> arr[i].first;
    }

    sort(arr.begin(), arr.end());

    long long answer = 0;
    for(int i = 0; i < n; i++){
        answer += arr[i].second + (t - n + i) * arr[i].first;
    }
    
    cout << answer;

    return 0;
}