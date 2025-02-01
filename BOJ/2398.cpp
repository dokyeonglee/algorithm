#include <iostream>
#include <queue>

using namespace std;

vector<pair<pair<int, int>, int>> dijkstra(vector<vector<pair<int, int>>>& adj, int src){
   
    vector<pair<pair<int, int>, int>> distance(adj.size(), make_pair(make_pair(1e8, 1e8), -1));
    distance[src] = make_pair(make_pair(0, 0), -1);

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, src);

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(distance[now].first.first < dist){
            continue;
        }
        for(auto& e : adj[now]){
            int next = e.first;
            auto p = make_pair(make_pair(dist + e.second, distance[now].first.second + 1), now);
            if(p.first.first < distance[next].first.first){
                distance[next] = p;
                pq.emplace(-p.first.first, next);
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
    
    while(m--){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<int> src(3);
    vector<vector<pair<pair<int, int>, int>>> distance(3);
    
    for(int i = 0; i < 3; i++){
        cin >> src[i];
        distance[i] = dijkstra(adj, src[i]);
    }

    int min_sum_of_distance = 1e9;
    int cnt = 0;
    int center = -1;

    for(int i = 1; i <= n; i++){
        int sum_of_distance = distance[0][i].first.first + distance[1][i].first.first + distance[2][i].first.first;
        if(min_sum_of_distance > sum_of_distance){
            min_sum_of_distance = sum_of_distance;
            cnt = distance[0][i].first.second + distance[1][i].first.second + distance[2][i].first.second;
            center = i;
        }
    }

    cout << min_sum_of_distance << " " << cnt << "\n";

    for(int i = 0; i < 3; i++){
        int now = center;
        while(now != src[i]){
            cout << now << " " << distance[i][now].second << "\n";
            now = distance[i][now].second;
        }
    }

    return 0;

}