#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> arr(n + 1);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int l, p;
    cin >> l >> p;

    sort(arr.begin(), arr.end() - 1);

    arr[n].first = l;

    priority_queue<int> pq;

    int answer = 0;
    int now = 0;

    for(int i = 0; i < n + 1; i++){
        while(!pq.empty() and now + p < arr[i].first){
            p += pq.top();
            pq.pop();
            answer++;
        }
        if(now + p < arr[i].first){
            cout << -1;
            return 0;
        }
        p -= arr[i].first - now;
        now = arr[i].first;
        pq.push(arr[i].second);
    }

    cout << answer;

    return 0;
}