#include <iostream>
#include <queue>

using namespace std;

long long dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<long long> distance(adj.size(), 1e18);
    distance[1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 1);

    vector<int> pred(adj.size());

    while(!pq.empty()){
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            long long cost = dist + e.second;
            if(distance[next] > cost){
                pred[next] = e.second;
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    long long result = 0;

    for(int i = 2; i < distance.size(); i++){
        result += distance[i] / 10 * 9;
    }

    for(int i = 2; i < distance.size(); i++){
        int temp = 1e9;
        for(auto j : adj[i]){
            if(distance[j.first] + j.second == distance[i]){
                temp = min(temp, j.second);
            }
        }
        if(temp != 1e9){
            result += temp / 10;
        }
    }

    return result;

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

    cout << dijkstra(adj);

    return 0;
}