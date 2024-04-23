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
    for(auto& a : arr){
        cin >> a.second >> a.first;
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int answer = 0;

    while(left <= right){

        int matched = min(arr[left].second, arr[right].second);

        arr[left].second -= matched;
        arr[right].second -= matched;

        answer = max(answer, arr[left].first + arr[right].first);

        if(arr[left].second <= 0){
            left++;
        }

        if(arr[right].second <= 0){
            right--;
        }
    
    }

    cout << answer;

    return 0;
}