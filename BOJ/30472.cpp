#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b){
    return (a.first - a.second) > (b.first - b.second);
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n + 1);

    long long answer = 0;
    long long base = 0;

    for(int i = 1; i <= n; i++){
        cin >> arr[i].first >> arr[i].second;
        answer += arr[i].first;
        base += arr[i].first - arr[i].second;
    }

    sort(arr.begin() + 1, arr.end(), compare);

    for(int i = 1; i <= n - 1; i++){
        answer += (long long)i * (arr[n - i].first - arr[n - i].second);
    }

    answer += -min(base, 0ll) * n;

    cout << answer;

    return 0;
}