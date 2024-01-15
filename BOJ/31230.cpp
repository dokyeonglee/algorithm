#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int src){

    vector<long long> distance(adj.size(), 1e18);
    distance[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, src);

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

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<pair<int, int>>> adj(n + 1);
    
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<long long> distance = dijkstra(adj, a);
    vector<long long> distance2 = dijkstra(adj, b);

    vector<int> answer;

    for(int i = 1; i <= n; i++){
        if(distance[i] + distance2[i] == distance[b]){
            answer.push_back(i);
        }
    }
    
    cout << answer.size() << "\n";

    for(int& x : answer){
        cout << x << " ";
    }

    return 0;
}