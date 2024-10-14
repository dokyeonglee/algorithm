#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& adj){

    vector<long long> distance(adj.size(), 1e18);
    distance[0] = 0;
    distance[adj.size() - 1] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.emplace(0, 0);
    pq.emplace(0, adj.size() - 1);


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

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> adj(n + 2);

    vector<int> arr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<int> brr(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> brr[i];
    }

    for(int i = 1; i <= n; i++){
        adj[max(0, i - arr[i])].emplace_back(i, brr[i]);
        adj[min(n + 1, i + arr[i])].emplace_back(i, brr[i]);
    }

    vector<long long> distance = dijkstra(adj);

    for(int i = 1; i <= n; i++){
        cout << distance[i] << " ";
    }


    return 0;
}