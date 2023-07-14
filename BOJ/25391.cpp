#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    return a.second > b.second;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), compare);

    long long answer = 0;
    for(int i = 0; i < k; i++){
        answer += arr[i].first;
    }

    sort(arr.begin() + k, arr.end(), greater<>());
    for(int i = k; i < m + k; i++){
        answer += arr[i].first;
    }

    cout << answer;

    return 0;
}