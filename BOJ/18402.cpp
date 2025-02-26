#include <iostream>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src){

    vector<int> distance(adj.size(), 1e9);
    distance[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){

        int now  = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            int cost = dist + e.second;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }

    }

    return distance;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, e, t, m;
    cin >> n >> e >> t >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[v].emplace_back(u, c);
    }

    int answer = 0;

    auto distance = dijkstra(adj, e);

    for(int i = 1; i <= n; i++){
        if(distance[i] <= t){
            answer++;
        }
    }

    cout << answer;

    return 0;

}