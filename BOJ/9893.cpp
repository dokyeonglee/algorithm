#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<pair<int, int>> distance(adj.size(), make_pair(-1e9, -1e9));
    distance[0] = make_pair(0, 0);

    vector<int> link(adj.size(), 1e9);
    vector<int> d(adj.size(), 1e9);

    priority_queue<pair<pair<int, int>, int>> pq;
    pq.emplace(make_pair(0, 0), 0);

    while(!pq.empty()){
        auto dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(distance[now] > dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            auto cost = make_pair(dist.first - 1, dist.second - e.second);
            if(cost > distance[next]){
                distance[next] = cost;
                pq.emplace(cost, next);
            }
        }
    }

    return -distance[1].second;

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
    }

    cout << dijkstra(adj);

    return 0;
}