#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst){

    vector<int> distance(adj.size(), 1e9);
    distance[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){

        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(dist > distance[now]){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            int cost = e.second + dist;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }

    }

    return distance[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    int s, t;
    cin >> s >> t;

    cout << dijkstra(adj, s, t);

    return 0;

}