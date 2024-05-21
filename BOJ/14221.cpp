#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& house, vector<int>& store){

    vector<int> distance(adj.size(), 1e9);
    for(int i = 0; i < store.size(); i++){
        distance[store[i]] = 0;
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i < store.size(); i++){
        pq.emplace(0, store[i]);
    }

    while(!pq.empty()){

        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
            continue;
        }

        for(auto& e : adj[now]){

            int next = e.first;
            int cost = dist + e.second;

            if(distance[next] > cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }

        }

    }

    int min_distance = 1e9;

    int result = adj.size();

    for(int i = 0; i < house.size(); i++){
        if(min_distance > distance[house[i]]){
            result = house[i];
            min_distance = distance[house[i]];
        }else if(min_distance == distance[house[i]]){
            result = min(result, house[i]);
        }
    }

    return result;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    int p, q;
    cin >> p >> q;

    vector<int> house(p);
    vector<int> store(q);

    for(int i = 0; i < p; i++){
        cin >> house[i];
    }

    for(int i = 0; i < q; i++){
        cin >> store[i];
    }

    cout << dijkstra(adj, house, store);

    return 0;
}