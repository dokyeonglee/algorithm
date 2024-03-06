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

vector<int> bfs(vector<vector<pair<int, int>>>& adj, int src){

    vector<int> distance(adj.size(), -1);
    distance[src] = 1;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto& e : adj[now]){
            int next = e.first;
            if(distance[next] == -1){
                distance[next] = distance[now] + 1;
                q.push(next);
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

    int toca, hanbyeol, school;
    cin >> toca >> hanbyeol >> school;


    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }

    vector<int> number_of_tree_from_school = bfs(adj, school);
    vector<long long> distance_from_toca = dijkstra(adj, toca);

    int d = number_of_tree_from_school[hanbyeol];

    int now = hanbyeol;

    int answer = now;
    long long min_dist = distance_from_toca[now];

    while(now != school){
        int max_sz = 0;
        int idx = -1;
        for(auto& e : adj[now]){
            int next = e.first;
            if(number_of_tree_from_school[next] == d - 1){
                if(max_sz < adj[next].size()){
                    max_sz = adj[next].size();
                    idx = next;
                }else if(max_sz == adj[next].size()){
                    idx = max(idx, next);
                }
            }
        }
        now = idx;
        if(distance_from_toca[now] < min_dist){
            min_dist = distance_from_toca[now];
            answer = now;
        }else if(distance_from_toca[now] == min_dist){
            answer = min(answer, now);
        }
        d--;
    }

    cout << answer;

    return 0;
}