#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].second >> arr[i].first;
        if(arr[i].second == 0){
            arr[i].second = -1;
        }
    }

    sort(arr.begin(), arr.end());

    int balance = n;
    int max_distance = 0;

    vector<int> balance_index(2 * n + 1, -1);
    balance_index[balance] = 0;

    for(int i = 0; i < n; i++){
        balance += arr[i].second;
        if(balance_index[balance] != -1){
            int prev_index = balance_index[balance];
            int distance = arr[i].first - arr[prev_index].first;
            max_distance = max(max_distance, distance);
        }else{
            balance_index[balance] = i + 1;
        }
    }

    cout << max_distance;

    return 0;

}