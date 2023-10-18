#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    stable_sort(arr.begin(), arr.end(), compare);

    int answer = 0;

    for(int i = 0; i < n; i++){
        answer = max(answer, arr[i].second - i + 1);
    }

    cout << answer;

    return 0;
}