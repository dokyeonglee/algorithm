#include <iostream>
#include <queue>

using namespace std;

vector<int> fox_dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<int> distance(adj.size(), 1e9);
    distance[1] = 0;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);

    while(!pq.empty()){

        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if(distance[now] < dist){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            int cost = e.second + dist;
            if(distance[next] > cost){
                distance[next] = cost;
                pq.emplace(-cost, next);
            }
        }
    }

    return distance;

}

vector<vector<int>> wolf_dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<vector<int>> distance(adj.size(), vector<int>(2, 1e9));
    distance[1][0] = 0;

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.emplace(0, make_pair(0, 1));

    while(!pq.empty()){

        int now = pq.top().second.second;
        int state = pq.top().second.first;
        int dist = -pq.top().first;
        pq.pop();

        if(distance[now][state] < dist){
            continue;
        }

        for(auto& e : adj[now]){
            int next = e.first;
            int cost = dist;
            if(state == 0){
                cost += e.second / 2;
            }else{
                cost += e.second * 2;
            }
            if(distance[next][state ^ 1] > cost){
                distance[next][state ^ 1] = cost;
                pq.emplace(-cost, make_pair(state ^ 1, next));
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
        adj[u].emplace_back(v, 2 * c);
        adj[v].emplace_back(u, 2 * c);
    }

    vector<int> fox_distance = fox_dijkstra(adj);
    vector<vector<int>> wolf_distance = wolf_dijkstra(adj);

    int answer = 0;

    for(int i = 1; i <= n; i++){
        if(fox_distance[i] < min(wolf_distance[i][0], wolf_distance[i][1])){
            answer++;
        }
    }

    cout << answer;

    return 0;
}