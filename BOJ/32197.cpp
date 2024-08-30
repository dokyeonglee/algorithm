#include <iostream>
#include <queue>

using namespace std;

int bfs(vector<vector<pair<int, int>>>& adj, int src,int dst){

    vector<vector<int>> distance(adj.size(), vector<int>(2, 1e9));

    distance[src][0] = 0;
    distance[src][1] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;

    pq.emplace(0, make_pair(src, 0));
    pq.emplace(0, make_pair(src, 1));

    while(!pq.empty()){

        int now = pq.top().second.first;
        int dist = -pq.top().first;
        int t = pq.top().second.second;
        pq.pop();

        if(distance[now][t] < dist){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            int tt = e.second;
            int cost = dist + (t != tt);
            
            if(distance[next][tt] > cost){
                distance[next][tt] = cost;
                pq.emplace(-cost, make_pair(next, tt));
            }
        }
    }

    return min(distance[dst][0], distance[dst][1]);

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v,  t;
        cin >> u >> v >> t;
        adj[u].emplace_back(v, t);
        adj[v].emplace_back(u, t);
    }

    int src, dst;
    cin >> src >> dst;

    cout << bfs(adj, src, dst);

    return 0;
}