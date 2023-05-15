#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    long long sum = 0;
    priority_queue<int> pq;

    int answer = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        pq.push(arr[i]);
        while(!pq.empty() and sum >= m){
            sum -= 2 * pq.top();
            pq.pop();
            answer++;
        }
    }

    cout << answer;


    return 0;
}