#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dst, int k){

    vector<vector<int>> distance(graph.size(), vector<int>(k, 987654321));
    distance[src][0] = 0;

    priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));

    while(!pq.empty()){
        int now = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if(distance[now][dist % k] < dist){
            continue;
        }
        for(auto e : graph[now]){
            int next = e.first;
            int cost = e.second + dist;
            if(distance[next][cost % k] > cost){
                pq.push(make_pair(-cost, next));
                distance[next][cost % k] = cost;
            }
        }
    }

    return distance[dst][0];
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int src, dst;
    cin >> src >> dst;

    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(make_pair(v, c));
    }

    int answer = dijkstra(graph, src, dst, k);

    if(answer == 987654321){
        cout << "IMPOSSIBLE";
    }else{
        cout << answer;
    }

    return 0;
}