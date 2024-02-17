#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);

    priority_queue<pair<int, int>> pq;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        pq.emplace(-arr[i], i);
    }

    int r;
    cin >> r;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < r; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    int answer = 0;

    vector<bool> visited(n + 1);

    while(!pq.empty()){
        int val = -pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        if(visited[idx]){
            continue;
        }
        visited[idx] = true;
        answer = max(answer, val);
        if(--m == 0){
            cout << answer;
            return 0;
        }
        for(auto& e : adj[idx]){
            if(!visited[e.first]){
                arr[e.first] -= e.second;
                pq.emplace(-arr[e.first], e.first);
            }
        }
    }

    cout << answer;

    return 0;
}