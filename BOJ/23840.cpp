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

long long solve(vector<vector<long long>>& distance, vector<int>& arr, vector<vector<long long>>& dp, int now, int visited, int dst){

    int n = arr.size();

    if(visited == (1 << n) - 1){
        return distance[now][dst];
    }

    long long& ret = dp[now][visited];

    if(ret != -1){
        return ret;
    }

    ret = 1e18;

    for(int i = 1; i < n; i++){
        if(visited & (1 << i)){
            continue;
        }
        if(distance[now][arr[i]] == 1e18){
            continue;
        }
        ret = min(ret, solve(distance, arr, dp, i, visited | (1 << i), dst) + distance[now][arr[i]]);
    }

    return ret;

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

    vector<int> arr(p + 1);

    arr[0] = src;

    vector<vector<long long>> distance(p + 1);
    
    for(int i = 1; i <= p; i++){
        cin >> arr[i];
    }

    for(int i = 0; i <= p; i++){
        distance[i] = dijkstra(adj, arr[i]);
    }

    vector<vector<long long>> dp(22, vector<long long>(1 << 22, - 1));

    long long answer = solve(distance, arr, dp, 0, 1, dst);

    if(answer == 1e18){
        answer = -1;
    }

    cout << answer;

    return 0;
}