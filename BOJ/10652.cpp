#include <iostream>
#include <queue>
#include <cassert>
#include <climits>

using namespace std;

constexpr int BESSIE = 1;
constexpr int ELSIE = 2;

vector<int> dijkstra(const vector<vector<int>>& adj, int src){

    vector<int> distance(adj.size(), INT_MAX);
    distance[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){

        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(dist > distance[now]){
            continue;
        }

        for(const int& next : adj[now]){
            int cost = dist + 1;
            if(cost < distance[next]){
                distance[next] = cost;
                pq.emplace(cost, next);
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, e, p, n, m;
    cin >> b >> e >> p >> n >> m;

    assert(b >= 3 and b <= 40000);
    assert(e >= 3 and e <= 40000);
    assert(p >= 3 and p <= 40000);
    assert(n >= 3 and n <= 40000);
    assert(m >= 3 and m <= 40000);

    vector<vector<int>> adj(n + 1);

    while(m--){
        int u, v;
        cin >> u >> v;
        assert(u >= 1 and u <= n);
        assert(v >= 1 and v <= n);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto distance_from_bessie = dijkstra(adj, BESSIE);
    auto distance_from_elsie = dijkstra(adj, ELSIE);
    auto distance_from_barn = dijkstra(adj, n);

    long long answer = LLONG_MAX;

    for(int i = 1; i <= n; i++){
        long long result = 1ll * b * distance_from_bessie[i] + e * distance_from_elsie[i] + p * distance_from_barn[i];
        answer = min(answer, result);
    }

    cout << answer;

    return 0;

}