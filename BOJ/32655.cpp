#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<long long> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()){
        int now = pq.top().second;
        auto dist = -pq.top().first;
        pq.pop();
        if(dist > distance[now]){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            auto cost = dist + e.second;
            if(cost < distance[next]){
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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    auto distance = dijkstra(adj);

    int x;
    cin >> x;

    long long answer = 1e18;

    long long mod = 1ll * x * k;

    long long open = 0;
    long long close = k;

    for(int i = 1; i <= x; i++){
        int e;
        cin >> e;
        long long time = distance[e] % mod;
        if(time < open){
            answer = min(answer, distance[e] + open - time);
        }else if(time < close){
            answer = min(answer, distance[e]);
        }else{
            answer = min(answer, distance[e] + open - time + mod);
        }
        open += k;
        close += k;
    }

    cout << answer;

    return 0;
}