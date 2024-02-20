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

    long long l = 0;
    long long r = 0;

    for(int i = 0; i < n; i++){
        l += arr[i].second + arr[n - 1].first - arr[i].first;
    }

    for(int i = n - 1; i >= 0; i--){
        r += arr[i].second + arr[i].first - arr[0].first;
    }

    long long answer = 1e18;

    for(int i = 1; i < n - 1; i++){
        answer = min(answer, min(l - (arr[i].second + arr[n - 1].first - arr[i].first), r - (arr[i].second + arr[i].first - arr[0].first)));
    }

    answer = min(answer, min(l - (arr[0].second + arr[n - 1].first - arr[0].first), r - (arr[0].second + (n - 1) * (arr[1].first - arr[0].first))));
    answer = min(answer, min(l - (arr[n - 1].second + (n - 1) * (arr[n - 1].first - arr[n - 2].first)), r - (arr[n - 1].second + (arr[n - 1].first - arr[0].first))));

    cout << answer;

    return 0;
}