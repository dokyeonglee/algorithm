#include <iostream>
#include <queue>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<long long> distance(adj.size(), 1e18);
    distance[0] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 0);

    while(!pq.empty()){
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            long long cost = dist + e.second;
            if(distance[next] > cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    if(distance.back() == 1e18){
        return -1;
    }    

    return distance.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    vector<int> ward(n);
    for(auto& w : ward){
        cin >> w;
    }

    ward.back() = 0;

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(ward[u] == 1 or ward[v] == 1){
            continue;
        }
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    cout << dijkstra(adj);

    return 0;
}