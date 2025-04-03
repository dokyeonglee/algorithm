#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sz = (1 << n);

    vector<int> answer(sz);

    vector<pair<int, int>> arr(sz);
    for(int i = 0; i < sz; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int idx = 0;
    int temp = 0;

    while(idx < sz){
        while(temp < sz and arr[idx].first == arr[temp].first){
            temp++;
        }
        int r = log2(temp);
        for(int i = idx; i < temp; i++){
            answer[arr[i].second] = n - r;
        }
        idx = temp;
    }

    for(auto& a : answer){
        cout << a << " ";
    }

    return 0;

}