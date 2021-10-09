#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dijkstra(vector<vector<pair<int, int>>>& adj, int src){
	
	vector<int> distance(adj.size(), 987654321);
	distance[src] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	
	while(!pq.empty()){
		
		int dist = -pq.top().first;
		int now = pq.top().second;
		
		pq.pop();
		
		if(distance[now] < dist){
			continue;
		}
		
		for(pair<int, int> e : adj[now]){
			
			int cost = dist + e.first;
			int next = e.second;
			
			if(cost < distance[next]){
				pq.push(make_pair(-cost, next));
				distance[next] = cost;
			}
			
		}
		
	}
	
	return distance.back();	
}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		adj[u].push_back(make_pair(c, v));
		adj[v].push_back(make_pair(c, u));
	}
	
	cout << dijkstra(adj, 1);
	
	
	return 0;
}