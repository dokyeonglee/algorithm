#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end());

    int answer = 0;

    int left = -1987654321;
    int right = -1987654321;

    for(int i = 0; i < n; i++){
        if(right < arr[i].first){
            answer += right - left;
            left = arr[i].first;
            right = arr[i].second;
        }else{
            right = max(right, arr[i].second);
        }
    }

    answer += right - left;

    cout << answer;

    return 0;
}