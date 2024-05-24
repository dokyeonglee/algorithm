#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, int a, int b, int c){

    vector<long long> distance(adj.size(), 1e18);
    distance[a] = distance[b] = distance[c] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, a);
    pq.emplace(0, b);
    pq.emplace(0, c);

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

    long long max_distance = 0;

    int result = 0;

    for(int i = 1; i < distance.size(); i++){
        if(max_distance < distance[i]){
            result = i;
            max_distance = distance[i];
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    int m;
    cin >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    cout << dijkstra(adj, a, b, c);

    return 0;
}