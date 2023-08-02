#include <iostream>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<int> distance(adj.size(), 987654321);
    vector<int> predecessor(adj.size(), -1);

    distance[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto e : adj[now]){
            int next = e.first;
            int cost = e.second + dist;
            if(distance[next] > cost){
                distance[next] = cost;
                predecessor[next] = now;
                pq.push(make_pair(-cost, next));
            }
        }
    }

    for(int i = 2; i < adj.size(); i++){
        cout << i << " " << predecessor[i] << "\n";
    }

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
        adj[u].push_back(make_pair(v, c));
        adj[v].push_back(make_pair(u, c));
    }

    cout << n - 1 << "\n";
    dijkstra(adj);

    return 0;
}