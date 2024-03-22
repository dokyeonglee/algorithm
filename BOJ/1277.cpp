#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

double get_distance(pair<long long, long long>& a, pair<long long, long long>& b){
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

long long dijkstra(vector<vector<pair<int, double>>>& adj, vector<pair<long long, long long>>& pos, double m){

    vector<double> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<double, int>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()){
        int now = pq.top().second;
        double dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto e : adj[now]){
            int next = e.first;
            double cost = dist + e.second;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return (long long)(1000 * distance.back());

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    double m;
    cin >> m;

    vector<pair<long long, long long>> pos(n + 1);
    for(long long i = 1; i <= n; i++){
        cin >> pos[i].first >> pos[i].second;
    }

    vector<vector<pair<int, double>>> adj(n + 1);
    while(w--){
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 0);
        adj[v].emplace_back(u, 0);
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            double d = get_distance(pos[i], pos[j]);
            if(d > m){
                continue;
            }
            adj[i].emplace_back(j, d);
            adj[j].emplace_back(i, d);
        }
    }

    cout << dijkstra(adj, pos, m);

    return 0;
}