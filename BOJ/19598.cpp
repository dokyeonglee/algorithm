#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n);
    for(auto& p : arr){
        cin >> p.first >> p.second;
    }

    sort(arr.begin(), arr.end());

    priority_queue<int> pq;

    for(int i = 0; i < n; i++){
        if(!pq.empty() and -pq.top() <= arr[i].first){
            pq.pop();
        }
        pq.push(-arr[i].second);
    }

    cout << pq.size();

    return 0;
}