#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, vector<int>& arr, int src, int dst){

    vector<long long> distance(adj.size(), 1e18);
    distance[src] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, src);

    vector<int> min_value_in_path_until(adj.size(), 1e9);
    vector<int> result(adj.size(), 1e9);

    while(!pq.empty()){

        int now = pq.top().second;
        auto dist = -pq.top().first;
        pq.pop();

        if(dist > distance[now]){
            continue;
        }

        result[now] = min(result[now], min_value_in_path_until[now] + arr[now]);
        min_value_in_path_until[now] = min(min_value_in_path_until[now], arr[now]);

        for(auto& e : adj[now]){
            int next = e.first;
            auto cost = dist + e.second;
            if(cost < distance[next]){
                distance[next] = cost;
                result[next] = result[now];
                min_value_in_path_until[next] = min_value_in_path_until[now];
                pq.emplace(-cost, next);
            }else if(cost == distance[next]){
                result[next] = min(result[now], result[next]);
                min_value_in_path_until[next] = min(min_value_in_path_until[now], min_value_in_path_until[next]);
            }
        }

    }

    if(distance[dst] == 1e18){
        return -1;
    }

    return result[dst];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    int s, t;
    cin >> s >> t;


    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    cout <<  dijkstra(adj, arr, s, t);

    return 0;
}