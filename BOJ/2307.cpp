#include <iostream>
#include <queue>

using namespace std;

vector<int> predecessor;

int dijkstra(vector<vector<pair<int, int>>>& adj, bool nonblocked, pair<int, int> blocked_edge = {0, 0}){

    vector<int> distance(adj.size(), 1e9);
    distance[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);

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
            if(now == blocked_edge.first and next == blocked_edge.second){
                continue;
            }
            if(next == blocked_edge.first and now == blocked_edge.second){
                continue;
            }
            if(cost < distance[next]){
                if(nonblocked){
                    predecessor[next] = now;
                }
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
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    predecessor.resize(n + 1, -1);
    predecessor[1] = 1;

    int nonblocked_time = dijkstra(adj, true);
    int blocked_time = 0;

    for(int now = n; now != predecessor[now]; now = predecessor[now]){
        int u = now;
        int v = predecessor[now];
        blocked_time = max(blocked_time, dijkstra(adj, false, make_pair(u, v)));
        if(blocked_time == 1e9){
            break;
        }
    }

    if(blocked_time == 1e9){
        cout << -1;
    }else{
        cout << blocked_time - nonblocked_time;
    }


    return 0;
}