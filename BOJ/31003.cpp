#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int& a : arr){
        cin >> a;
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(gcd(arr[i], arr[j]) != 1){
                adj[i].push_back(j);
                in_degree[j]++;
            }
        }
    }

    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < n; i++){
        if(in_degree[i] == 0){
            pq.emplace(-arr[i], i);
        }
    }

    while(!pq.empty()){
        int now = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        cout << now << " ";
        for(int& next : adj[idx]){
            if(--in_degree[next] == 0){
                pq.emplace(-arr[next], next);
            }
        }
    }


    return 0;
}