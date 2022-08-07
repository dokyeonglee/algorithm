#include <iostream>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dst){
	
	vector<int> distance(graph.size(), 987654321);
	distance[src] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int now = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(auto e : graph[now]){
			int next = e.first;
			int cost = dist + e.second;
			if(distance[next] > cost){
				distance[next] = cost;
				pq.push(make_pair(-cost, next));
			}
		}
	}
	
	return distance[dst];
	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, c, src, dst;
	cin >> n >> c >> src >> dst;
	
	vector<vector<pair<int, int>>> graph(n + 1);
	for(int i = 0; i < c; i++){
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back(make_pair(v, c));
		graph[v].push_back(make_pair(u, c));
	}
	
	cout << dijkstra(graph, src, dst);
	
	return 0;
}