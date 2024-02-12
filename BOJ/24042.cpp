#include <iostream>
#include <queue>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj, int m){

    vector<long long> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()){

        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
            continue;
        }

        for(auto& e : adj[now]){

            int next = e.first;
            long long cost = dist + e.second - dist % m + 1;

            if(dist % m > e.second){
                cost += m;
            }

            if(distance[next] > cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }

        }

    }

    return distance.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    cout << dijkstra(adj, m);

    return 0;
}