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

    long long total = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
        total += arr[i].second;
    }

    sort(arr.begin(), arr.end());

    long long sum = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i].second;
        if(sum * 2 >= total){
            cout << arr[i].first;
            return 0;
        }
    }

    return 0;
}