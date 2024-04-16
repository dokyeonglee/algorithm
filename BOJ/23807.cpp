#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj, int src){

    vector<long long> distance(adj.size(), 1e18);
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

    return distance;

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

    int src, dst;
    cin >> src >> dst;

    int p;
    cin >> p;

    vector<int> arr(p);

    vector<vector<long long>> distance(p + 1);
    
    for(auto& a : arr){
        cin >> a;
    }

    for(int i = 0; i < p; i++){
        distance[i] = dijkstra(adj, arr[i]);
    }

    long long answer = 1e18;

    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            if(i == j){
                continue;
            }
            for(int k = 0; k < p; k++){
                if(i == k or j == k){
                    continue;
                }
                answer = min(answer, distance[i][src] + distance[i][arr[j]] + distance[j][arr[k]] + distance[k][dst]);
            }    
        }
    }

    if(answer == 1e18){
        answer = -1;
    }

    cout << answer;

    return 0;
}