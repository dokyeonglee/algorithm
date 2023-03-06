#include <iostream>
#include <queue>

using namespace std;

vector<long long> dijkstra(vector<vector<pair<int, int>>>& graph, vector<int>& src){

    vector<long long> distance(graph.size(), 1e18);
    
    priority_queue<pair<long long, int>> pq;
    for(int i = 0; i < src.size(); i++){
        distance[src[i]] = 0;
        pq.push(make_pair(0, src[i]));
    }

    while(!pq.empty()){
        int now = pq.top().second;
        long long dist = -pq.top().first;
        pq.pop();
        if(distance[now] < dist){
            continue;
        }
        for(auto e : graph[now]){
            int next = e.first;
            long long cost = e.second + dist;
            if(distance[next] > cost){
                distance[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }

    return distance;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[v].push_back(make_pair(u, c));
    }

    vector<int> interview(k);
    for(int i = 0; i < k; i++){
        cin >> interview[i];       
    }

    vector<long long> distance = dijkstra(graph, interview);

    long long answer = -1;
    int idx = -1;

    for(int i = 1; i <= n; i++){
        if(answer < distance[i]){
            answer = distance[i];
            idx = i;
        }
    }

    cout << idx << "\n";
    cout << answer;

    return 0;
}