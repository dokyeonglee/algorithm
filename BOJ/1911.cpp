#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;

    vector<pair<long long, long long>> arr(n);

    for(auto& a : arr){
        cin >> a.first >> a.second;
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    long long right = 0;

    for(int i = 0; i < n; i++){
        right = max(right, arr[i].first);
        int x = (arr[i].second - right + l - 1) / l;
        answer += x;
        right += x * l;
    }

    cout << answer;

    return 0;
}