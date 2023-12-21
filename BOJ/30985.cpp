#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int v){

    vector<long long> distance(adj.size(), 1e18);
    distance[v] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, v);

    while(!pq.empty()){
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            long long cost = e.second + dist;
            if(distance[next] > cost){
                pq.emplace(-cost, next);
                distance[next] = cost;
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<long long> e(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> e[i];
    }

    vector<long long> distance_from_src = dijkstra(adj, 1);
    vector<long long> distance_to_dst = dijkstra(adj, n);

    long long answer = 1e18;

    for(int i = 1; i <= n; i++){
        if(e[i] != -1){
            if(distance_from_src[i] != 1e18 and distance_to_dst[i] != 1e18){
                answer = min(answer, distance_from_src[i] + distance_to_dst[i] + (k - 1) * e[i]);
            }
        }
    }

    if(answer == 1e18){
        answer = -1;
    }

    cout << answer;

    return 0;
}