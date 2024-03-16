#include <iostream>
#include <queue>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<int> distance(adj.size(), 1e9);
    distance[2] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 2);

    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto e : adj[now]){
            int next = e.first;
            int cost = dist + e.second;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance;

}

int solve(vector<vector<pair<int, int>>>& adj, vector<int>& distance, vector<int>& dp, int now){

    if(now == 2){
        return 1;
    }

    int& ret = dp[now];

    if(ret != -1){
        return ret;
    }

    ret = 0;

    for(auto& e : adj[now]){
        int next = e.first;
        if(distance[now] > distance[next]){
            ret += solve(adj, distance, dp, next);
        }
    }

    return ret;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<int> distance = dijkstra(adj);

    vector<int> dp(n + 1, -1);

    cout << solve(adj, distance, dp, 1);

    return 0;
}