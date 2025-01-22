#include <iostream>
#include <queue>

using namespace std;

const int mod = 1e9 + 9;

void dijkstra(vector<vector<pair<int, int>>>& adj, int src, int dst){
    
    
    vector<pair<long long, int>> distance(adj.size(), make_pair(1e18, 1e18));
    distance[src] = make_pair(0, 0);

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, src);

    vector<long long> dp(adj.size());

    dp[src] = 1;

    while(!pq.empty()){

        long long dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(distance[now].first < dist){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            auto p = make_pair(dist + e.second, distance[now].second + 1);
            if(p < distance[next]){
                distance[next] = p;
                pq.emplace(-p.first, next);
                dp[next] = dp[now];
            }else if(p == distance[next]){
                dp[next] = (dp[now] + dp[next]) % mod;
            }
        }

    }

    if(distance[dst].first == 1e18){
        cout << -1;
        return;
    }

    cout << distance[dst].first << "\n";
    cout << distance[dst].second << "\n";
    cout << dp[dst];

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, src, dst;
    cin >> n >> m >> src >> dst;

    vector<vector<pair<int, int>>> adj(n + 1);

    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
    }

    dijkstra(adj, src, dst);

    return 0;

}