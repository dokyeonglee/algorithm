#include <iostream>
#include <queue>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<long long> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 1);

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

    return distance.back();

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> is_prime(1e7 + 1, true);
    
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= 1e7; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= 1e7; j += i){
                is_prime[j] = false;
            }
        }
    }

    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        if(is_prime[d[u] + d[v]]){
            adj[u].emplace_back(v, c);
            adj[v].emplace_back(u, c);
        }
    }

    long long answer = dijkstra(adj);

    if(answer == 1e18){
        cout << "Now where are you?";
    }else{
        cout << answer;
    }

    return 0;
}