#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<pair<int, int>, pair<int, int>>> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second.first >> arr[i].second.second;
    }

    sort(arr.begin(), arr.end());

    int answer = 0;
    pair<int, int> now = {3, 1};
    pair<int, int> target = {11, 30};

    int idx = 0;
    while(idx < n and now <= target){
        pair<int, int> temp = {0, 0};
        while(idx < n and arr[idx].first <= now and temp <= target){
            temp = max(temp, arr[idx++].second);
        }
        if(temp.first == 0){
            break;
        }
        if(temp > now){
            now = temp;
            answer++;
        }
    }
    
    if(now > target){
        cout << answer;
    }else{
        cout << 0;
    }

    return 0;
}