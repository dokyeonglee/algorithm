#include <iostream>
#include <queue>
#include <map>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst){

    vector<int> distance(adj.size());
    distance[src] = 1e9;

    priority_queue<pair<int, int>> pq;
    pq.emplace(-1e9, src);

    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now] > dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            int cost = min(dist, e.second);
            if(distance[next] < cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance[dst];

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int scenario_number = 1;

    while(1){

        int n, m;
        cin >> n >> m;

        if(n == 0 and m == 0){
            break;
        }

        map<string, int> name_to_int;
        int cnt = 0;

        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < m; i++){
            string u, v;
            int c;
            cin >> u >> v >> c;
            if(name_to_int.count(u) == 0){
                name_to_int[u] = ++cnt;                
            }
            if(name_to_int.count(v) == 0){
                name_to_int[v] = ++cnt;
            }

            adj[name_to_int[u]].emplace_back(name_to_int[v], c);
            adj[name_to_int[v]].emplace_back(name_to_int[u], c);

        }

        string src, dst;
        cin >> src >> dst;

        int answer = n;

        cout << "Scenario #" << scenario_number++ << "\n";
        cout << dijkstra(adj, name_to_int[src], name_to_int[dst]) << " tons\n\n";

    }

    return 0;
}