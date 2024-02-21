#include <iostream>
#include <queue>

using namespace std;

const long long inf = (long long)1e18 + 1;

long long dijkstra(vector<vector<pair<int, long long>>>& adj, int src, int dst){

    vector<long long> distance(adj.size(), inf);
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
            long long cost = e.second + dist;

            if(distance[next] > cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }

        }
    }

    return distance[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<pair<long long, long long>> result;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<pair<int, long long>>> adj(n + 1);

        for(int i = 0; i < m; i++){

            int u, v, c;
            cin >> u >> v >> c;

            if(c >= 0){
                adj[u].emplace_back(v, c);
            }else{
                if(result[-c - 1].first != inf){
                    adj[u].emplace_back(v, result[-c - 1].first);
                }
                if(result[-c - 1].second != inf){
                    adj[v].emplace_back(u, result[-c - 1].second);
                }
            }

        }
        result.emplace_back(dijkstra(adj, 1, 2), dijkstra(adj, 2, 1));
    }

    if(result.back().first == inf){
        result.back().first = -1;
    }

    cout << result.back().first;

    return 0;
}