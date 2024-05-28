#include <iostream>
#include <queue>

using namespace std;

bool dijkstra(vector<vector<pair<int, pair<int, int>>>>& adj, int mid){

    vector<long long> distance(adj.size(), 1e18);
    distance[1] = mid;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(-mid, 1);

    while(!pq.empty()){
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            long long cost = dist + e.second.first;
            int limit = e.second.second;
            if(distance[next] > cost and cost <= limit){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance.back() != 1e18;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, pair<int, int>>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, d, t;
        cin >> u >> v >> d >> t;
        adj[u].emplace_back(v, make_pair(d, t));
        adj[v].emplace_back(u, make_pair(d, t));
    }

    int left = 0;
    int right = 1e9;

    int answer = 1e9;

    while(left <= right){
        int mid = (left + right) / 2;
        if(dijkstra(adj, mid)){
            answer = mid;
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    if(answer == 1e9){
        answer = -1;
    }

    cout << answer;

    return 0;
}