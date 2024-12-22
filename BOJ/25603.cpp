#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>> pq;

    int answer = 0;

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        pq.emplace(-a, i);
        if(i < k) continue;
        while(!pq.empty() and pq.top().second <= i - k){
            pq.pop();
        }
        answer = max(answer, -pq.top().first);
    }

    cout << answer;

    return 0;
}